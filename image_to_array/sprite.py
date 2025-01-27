import os
from PIL import Image
import base64

# Görseli bitmap formatına çevirme
def image_to_bitmap(image_path):
    img = Image.open(image_path).convert('1')  # Görseli siyah-beyaz (1 bit) yap
    width, height = img.size
    bitmap = []

    for y in range(height):
        byte = 0
        for x in range(width):
            pixel = img.getpixel((x, y))  # Piksel değeri
            pixel_value = 1 if pixel == 0 else 0  # Siyah için 1, beyaz için 0
            byte |= (pixel_value << (7 - x % 8))  # 1 bit'lik piksel değerini byte'a ekle
            if (x + 1) % 8 == 0 or x == width - 1:
                bitmap.append(byte)
                byte = 0  # Sonraki byte için sıfırla

    return bitmap

# Görseli base64 formatına çevirme
def image_to_base64(image_path):
    bitmap = image_to_bitmap(image_path)
    byte_data = bytearray(bitmap)
    return base64.b64encode(byte_data).decode('utf-8')

# Tüm emote'ları base64 formatında dosyaya yazma
array_list = []
emotes_path_name = os.path.join(os.path.dirname(__file__), "emotes")
emote_path = os.path.join(emotes_path_name, "eye_on")

# Dosya üzerine yazma işlemini döngü dışında yapıyoruz
with open("emote_base64.txt", "w") as file:
    i = 0
    for item in os.listdir(emote_path):
        image_path = os.path.join(emote_path, item)
        base64_data = image_to_base64(image_path)
        file.write(f"{i}:\n{base64_data}\n\n")
        i += 1

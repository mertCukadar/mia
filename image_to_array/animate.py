import os
import cv2
import requests
import PIL


def serialize(self, frame):
        _, f = cv2.threshold(frame, self.threshold, 1, cv2.THRESH_BINARY)
        serialized = ""
        for i in range(self.screenSize[1]):
            for j in range(self.screenSize[0]):
                serialized += str(f[i][j])
        finale = []
        for i in range(0, len(serialized), 8):
           finale.append(int(serialized[i:i+8], 2).to_bytes(1, 'little'))
        return b"".join(finale)


array_list = []
emotes_path_name = os.path.join(os.path.dirname(__file__), "emotes")
emote_path = os.path.join(emotes_path_name, "test")

for item in os.listdir(emote_path):
    img = cv2.imread(os.path.join(emote_path, item))
    max_width = 128
    max_height = 64

    resized_img = cv2.resize(img, (max_width, max_height), interpolation=cv2.INTER_AREA)

    bw_img = cv2.cvtColor(resized_img, cv2.COLOR_BGR2GRAY)

    bw_img = cv2.threshold(bw_img, 150, 1, cv2.THRESH_BINARY)[1]


    bitmap = serialize(bw_img)
                          
    print(bitmap)
    # for i in range(bw_img.shape[0]):
    #     for j in range(bw_img.shape[1]):
    #         bw_img.to
    #         array_list.append(str(int(bw_img[i][j])))

screen_width = 128
screen_height = 64
one_screen = screen_width * screen_height

string_val = "".join(array_list)
chunks = [string_val[i:i+one_screen] for i in range(0, len(string_val), one_screen)]





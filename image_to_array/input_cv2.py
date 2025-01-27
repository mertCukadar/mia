import os
import cv2
import requests

img = cv2.imread("input.png")
height, width = img.shape[:2]

max_width = 128
max_height = 64

resized_img = cv2.resize(img, (max_width, max_height), interpolation=cv2.INTER_AREA)
# cv2.imwrite("output.jpeg", resized_img)

bw_img = cv2.cvtColor(resized_img, cv2.COLOR_BGR2GRAY)

bw_img = cv2.threshold(bw_img, 150, 1, cv2.THRESH_BINARY)[1]



print(bw_img.shape)
print(bw_img.shape[0])
print(bw_img.shape[1])

array_list = []
for i in range(bw_img.shape[0]):
    for j in range(bw_img.shape[1]):
        array_list.append(str(int(bw_img[i][j])))



print("".join(array_list))
response = requests.post("http://192.168.1.37/screen/draw/", data={"data": "".join(array_list)})

print(response.text)
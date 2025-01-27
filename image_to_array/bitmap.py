import cv2
import time
import os


class MiaCodec:
    def __init__(self, threshold, screenSize=(128, 64)):
        self.threshold = threshold
        self.screenSize = screenSize


    def extract_frames(self, video):
        prev = time.time()
        frames = []
        # frameNo = 0
        while True:
            success, frame = video.read()
            if not success:
                break
            resized = cv2.resize(frame, self.screenSize)
            gFrame = cv2.cvtColor(resized, cv2.COLOR_BGR2GRAY)
            _, bwFrame = cv2.threshold(gFrame, self.threshold, 255, cv2.THRESH_BINARY)
            frames.append(bwFrame)
            # frameNo += 1
            # if frameNo == 100:
            #     break
        print(f"Video frames extracted in: {time.time() - prev}")
        return frames


    def get_differences(self, frames):
        _, previousFrame = cv2.threshold(frame, self.threshold, 1, cv2.THRESH_BINARY)
        for frame in frames[1:]:
            _, finalFrame = cv2.threshold(frame, self.threshold, 1, cv2.THRESH_BINARY)


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


    def deserialize(self, serialized):
        finalMatrix = []
        for i in range(self.screenSize[1]):
            row = []
            for j in range(self.screenSize[0]):
                row.append((serialized[(i*self.screenSize[0]+j)//8] >> (7 - (i*self.screenSize[0]+j) % 8)) & 0x1)
            finalMatrix.append(row)
        return finalMatrix


    def old_serialize(self, frame):
        _, f = cv2.threshold(frame, self.threshold, 1, cv2.THRESH_BINARY)
        serialized = ""
        for i in range(self.screenSize[1]):
            for j in range(self.screenSize[0]):
                serialized += str(f[i][j])
        return serialized


    def old_deserialize(self, serialized):
        finalMatrix = []
        for i in range(self.screenSize[1]):
            row = []
            for j in range(self.screenSize[0]):
                row.append(int(serialized[i*self.screenSize[0]+j]))
            finalMatrix.append(row)
        return finalMatrix


    def visualize(self, frames):
        for frame in frames:
            cv2.imshow("VideoFeed", frame)
            if cv2.waitKey(1) == 27:
                break
        cv2.destroyAllWindows()


    def simulateScreen(self, frameMatrix):
        import matplotlib.pyplot as plt
        f = plt.figure()
        plt.imshow(frameMatrix, cmap='Greys', interpolation='nearest')
        plt.show()


import requests


def send_to_screen(frame):
    print(frame)
    requests.post("http://192.168.1.37/screen/draw/", data={"data":frame})



emotes_path_name = os.path.join(os.path.dirname(__file__), "emotes")
emote_path = os.path.join(emotes_path_name, "test")
codec = MiaCodec(127)

fin = ""
for item in os.listdir(emote_path):
    img = cv2.imread(os.path.join(emote_path, item))
    max_width = 128
    max_height = 64

    resized_img = cv2.resize(img, (max_width, max_height), interpolation=cv2.INTER_AREA)

    bw_img = cv2.cvtColor(resized_img, cv2.COLOR_BGR2GRAY)

    # bw_img = cv2.threshold(bw_img, 150, 1, cv2.THRESH_BINARY)[1]


    bitmap = bw_img.tobytes()
    save_path = os.path.join(emote_path, "bw_img")
    
bitmap = codec.serialize(bw_img)
a = [format(byte, "#04x") for byte in bitmap]
fin += (",".join(a)) + ","



print("{ " + fin[:-1] + " };")
# codec = MiaCodec(127)
# frames = codec.extract_frames(video)

# for frame in frames:
#     a = codec.old_serialize(frame)
#     send_to_screen(a)

# codec.visualize(frames)

# origarray = frames[89][:]

# Old serialization
# a = codec.old_serialize(origarray)
# print(f"Number of bytes old serialization takes: {len(a)}")
# b = codec.old_deserialize(a)
# codec.simulateScreen(b)

# New serialization 
# 8 times better than old one.
# c = codec.serialize(origarray)
# print(f"Number of bytes new serialization takes: {len(c)}")
# d = codec.deserialize(c)
# codec.simulateScreen(d)
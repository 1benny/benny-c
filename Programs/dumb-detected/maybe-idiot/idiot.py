import cv2
import ffpyplayer.player
import numpy as np
import threading

video_path="idiot.mp4"

def PlayVideo(video_path):
    video=cv2.VideoCapture(video_path)
    player = ffpyplayer.player.MediaPlayer(video_path)
    while True:
        grabbed, frame=video.read()
        audio_frame, val = player.get_frame()
        if not grabbed:
            break
        if cv2.waitKey(28) & 0xFF == ord("q"):
            break
        cv2.imshow("you are an idiot!!", frame)
        if val != 'eof' and audio_frame is not None:
            #audio
            img, t = audio_frame
    video.release()

while True:
    PlayVideo(video_path)
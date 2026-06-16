#Nothing really complex, pretty basic and funny =)

import serial
import pyautogui

ser = serial.Serial('COM3', 9600)

print("Ready!")

while True:
    line = ser.readline().decode().strip()
    print(line)
    if line == "JUMP":
        pyautogui.press('space')
        print("Jumped")
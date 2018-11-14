import serial
from tkinter import*
import tkinter

arduinoData = serial.Serial('COM3',9600)

def led_on():
    arduinoData.write(b'1')
    print("Encender")
def led_off():
    arduinoData.write(b'0')
    print("Apagar")

led_control_window = Tk()
btn1 = Button(led_control_window, text ="ON", command=led_on)
btn2 = Button(led_control_window, text ="OFF", command=led_off)

btn1.grid(row=0,column=1)
btn2.grid(row=1,column=1)

led_control_window.mainloop()

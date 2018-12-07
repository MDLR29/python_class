#Proyecto final.py

import serial
from tkinter import*
import tkinter

#arduinoData = serial.Serial ('COM10',9600)

def on_offLuces(valor):
        print ("encender/apagar")
        #arduinoData.write(b'valor')
        arduinoData.write(str.encode(valor))
def luces():
	luz=Tk()
	luz.title("Luces")
	luz.geometry("400x200")
	luz.configure (background="black")
	luz.resizable(FALSE, FALSE)
	print ("luces")
	luces_Cocina = Button(luz, text="L_Cocina",width=10,height=3, command= lambda :on_offLuces('1')).place (x=10, y=40)
	luces_Habitacion = Button(luz, text="L_Habitacion",width=10,height=3, command= lambda :on_offLuces('2')).place (x=110, y=40)
	luces_Letrero = Button(luz, text="L_Letrero",width=10,height=3, command=lambda :on_offLuces('6')).place (x=210, y=40)
	luces_Garaje = Button(luz, text="L_Garaje",width=10,height=3, command=lambda :on_offLuces('4')).place (x=310, y=40)
	luces_Escalera = Button(luz, text="L_Escalera",width=10,height=3, command=lambda :on_offLuces('3')).place (x=170, y=120)
	luces_Disco = Button(luz, text="L_discoteca",width=10,height=3, command=lambda :on_offLuces('5')).place (x=80, y=120)
        
def todo():
       todo=Tk()
       todo.title("ON/OFF_Todo")
       todo.geometry("400x200")
       todo.resizable(FALSE, FALSE)
       todo.configure (background="yellow")
       print ("Encender y apagar todo")
       todo = Button(todo, text="ON/OFF",width=5,height=3,command= lambda :on_offLuces('7')).place (x=10, y=60)

def servo1():
        servo=Tk()
        servo.title("Sensor")
        servo.geometry("400x200")
        servo.resizable(FALSE, FALSE)
        servo.configure (background="green")
        print ("Abrir/Cerrar puerta")
        PuertaGaraje = Button(servo, text="Garaje",width=15,height=3,command = lambda:on_offLuces('8')).place (x=10, y=60)


	
domotica=Tk()
domotica.title("Casa_Domotica")
domotica.geometry("300x400")
domotica.resizable(FALSE, FALSE)
domotica.configure(background="SkyBlue4")
color_boton=("gray77")

BotonLuz=Button(domotica,text="Luces",width=30,height=3,command=luces).place(x=50,y=50)
BotonTodo=Button(domotica,text="ON/OFF_Todo",width=30,height=3,command=todo).place(x=50,y=110)
BotonServoG=Button(domotica,text="Puerta_Garaje",width=30,height=3,command=servo1).place(x=50,y=170)

domotica.mainloop()
arduinoData.close()

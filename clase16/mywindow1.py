# HAROLD CHAMORRO KEVIN MOLINA MARLON DE LA ROSA
# importar librerias para gui
import serial
from tkinter import *
import tkinter
##########################################
#crear ventana
root= tkinter.Tk()
root.geometry("600x400")#wxh
root.title("mi calculadora")
root.resizable(FALSE,FALSE)
root.configure(background="#11BDB7")
arduinoData = serial.Serial('COM10',9600)
##########################################
def btnclick(valor):
    global operador
    
    operador=operador+str(valor)
    input_text.set(operador)
def clear():
    global operador
    operador=("")
    input_text.set(operador)
def operacion():
    global operador
    try:
        
        opera=str(eval(operador))
        arduinoData.write(b'1')
    except:
        clear()
        opera=("error")
    input_text.set(opera)
########################################## 
input_text=StringVar()
operador=""

Display=Entry(root,font=('arial',20,'bold'),width=22,bd=1,insertwidth=8,bg="#5B2C6F",justify="right",textvariable=input_text).place(x=30,y=45) 
Boton1=Button(root,text="1",width=7,height=3,command=lambda:btnclick(1)).place(x=10,y=180)
Boton2 = Button(root, text = "2", width = 7 , height = 3,command=lambda:btnclick(2)).place(x=70,y=180)
Boton3 = Button(root, text = "3", width = 7 , height = 3,command=lambda:btnclick(3)).place(x=130,y=180)
Boton4 = Button(root, text = "4", width = 7, height = 3,command=lambda:btnclick(4)).place(x=10,y=240)
Boton5 = Button(root, text = "5", width = 7 , height = 3,command=lambda:btnclick(5)).place(x=70,y=240)
Boton6 = Button(root, text = "6", width = 7 , height = 3,command=lambda:btnclick(6)).place(x=130,y=240)
Boton7 = Button(root, text = "7", width = 7 , height = 3,command=lambda:btnclick(7)).place(x=10,y=300)
Boton8 = Button(root, text = "8", width = 7 , height = 3,command=lambda:btnclick(8)).place(x=70,y=300)
Boton9 = Button(root, text = "9", width = 7 , height = 3,command=lambda:btnclick(9)).place(x=130,y=300)
Boton10 = Button(root, text = "0", width = 7 , height = 3,command=lambda:btnclick(9)).place(x=70,y=360)
Boton11 = Button(root, text = "+", width = 7 , height = 3,command=lambda:btnclick("+")).place(x=190,y=180)
Boton12 = Button(root, text = "-", width = 7 , height = 3,command=lambda:btnclick("-")).place(x=190,y=240)
Boton13 = Button(root, text = "*", width = 7 , height = 3,command=lambda:btnclick("*")).place(x=190,y=300)
Boton14 = Button(root, text = "=", width = 7 , height = 3,command=operacion).place(x=130,y=360)
Boton15 = Button(root, text = "/", width = 7 , height = 3,command=lambda:btnclick("/")).place(x=190,y=360)
Boton16 = Button(root, text = "C", width = 7 , height = 3,command=lambda:clear(
    )).place(x=10,y=360)
#Abrir ventana para el programa


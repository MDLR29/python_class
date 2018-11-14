import serial, time
time
arduino= serial.Serial('com7',9600)
time.sleep(2)
rawString = arduino.readline()
print (rawString)
arduino.close()

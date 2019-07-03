#! /usr/bin/env python

import serial
from os import system

ser = serial.Serial('/dev/ttyUSB0', 9600)
prevOutput = ""
while 1:
    #a = raw_input("Enter Command : ")
    #ser.write(a)
    output=ser.readline()
    while output != prevOutput:
            print(output)
            prevOutput = output
            output = ser.readline()
            if "CONFIRMED" in output:
                print("POWERING OFF RPI.......")
                system("poweroff")

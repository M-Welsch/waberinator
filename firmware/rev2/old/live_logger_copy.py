# data format
# datetime = Date and Time of Logger Raspi
# TimeRaspi,TimeAtmega,Temperature,BatteryVoltage,Frequency,Depth

import serial
import datetime

ser = serial.Serial ("/dev/ttyUSB0")    #Open named port 
ser.baudrate = 9600                     #Set baud rate to 9600

cTime = datetime.datetime.now().strftime("%d.%m.%Y %H:%M:%S")
logfile = open("logfile.log","a")
logfile.write("\n" + str(cTime) + ": Starting new Session\n")
logfile.close()

while True:
	raw_data = ''
	data = ''
	while raw_data != '\n':
		raw_data = ser.read(1) 			# read one character from serial
		data = data + raw_data             
		# print "data: " + data + ", raw_data = " + raw_data
	print data
	cTime = datetime.datetime.now().strftime("%d.%m.%Y %H:%M:%S")
	logfile = open("logfile.log","a")
	logfile.write(str(cTime) + "," + data)
	logfile.close()

ser.close()
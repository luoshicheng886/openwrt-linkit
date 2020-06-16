import pyupm_i2clcd as lcd
from time import localtime, strftime, sleep

myLcd = lcd.Lcm1602(0, 0x27)
last_date = ''
last_time = ''
myLcd.clear()
while (True):
	date_time = strftime("%Y-%m-%d %H:%M:%S", localtime()).split(' ')
	if (last_date != date_time[0]):
		myLcd.setCursor(0, 3)
		myLcd.write(date_time[0])
		last_date = date_time[0]
	if (last_time != date_time[1]):
		myLcd.setCursor(1, 4)
		myLcd.write(date_time[1])
		last_time = date_time[1]
	sleep(0.1)


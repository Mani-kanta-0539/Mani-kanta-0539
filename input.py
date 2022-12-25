import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

GPIO.setup(2,GPIO.IN)
while True:
    data=GPIO.input(2)
    print(data)
    time.sleep(1)
    

import Adafruit DHT 
import RPi.GPIO as GPIO

GPIO.setmode (GPIO.BCM)


while True:
  humidity, temperature = Adafruit_DHT.read_retry (Adafruit_DHT.DHT11, 2) 
  print("the temperature is",temperature)
  print("the humidity is",humidity)

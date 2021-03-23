output.o: crc.o i2c.o bme280.o gpio.o pid.o file.o pwm.o
	gcc binaries/* main.c -o output -lwiringPi -lpthread

file.o: file/writeCsv.c
	gcc -c file/writeCsv.c -o binaries/writeCsv.o

pid.o: pid/pid.c
	gcc -c pid/pid.c -o binaries/pid.o

pwm.o: pwm/wiringPi.c
	gcc -c pwm/wiringPi.c -o binaries/wiringPi.o -lwiringPi -lpthread

i2c.o: i2c/i2c.c
	gcc -c i2c/i2c.c -o binaries/i2c.o -lwiringPi

bme280.o: bme280/bme280.c
	gcc -c bme280/bme280.c -o binaries/bme280.o

gpio.o: gpioModbus/gpio.c
	gcc -c gpioModbus/gpio.c -o binaries/gpio.o

crc.o: gpioModbus/crc.c
	gcc -c gpioModbus/crc.c -o binaries/crc.o	

clear:
	rm -rf binaries/*
	rm output
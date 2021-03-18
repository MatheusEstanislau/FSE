output.o: i2c/i2c.o i2c/i2c.o bme280/bme280.o uartModBus/uart.o uartModBus/crc.o pwm/wiringPi.o pid/pid.o file/writeCsv.o
	gcc uartModBus/crc.o bme280/bme280.o uartModBus/uart.o i2c/i2c.o pwm/wiringPi.o pid/pid.o file/writeCsv.o main.c -o output -lwiringPi -lpthread
	./output

file.o: file/writeCsv.c
	gcc file/writeCsv.c -o file/writeCsv.o

pid.o: pid/pid.c
	gcc pid/pid.c -o pid/pid.o

pwm.o: pwm/wiringPi.c
	gcc pwm/wiringPi.c -o pwm/wiringPi.o -lwiringPi -lpthread

i2c.o: i2c/i2c.c
	gcc i2c/i2c.c -o i2c/i2c.o -lwiringPi

bme280.o: bme280/bme280.c
	gcc bme280/bme280.c -o bme280/bme280.o

uart.o: uartModBus/uart.c
	gcc uartModBus/uart.c -o uartModBus/uart.o

crc.o: uartModBus/crc.c
	gcc uartModBus/crc.c -o uartModBus/crc.o

clear:
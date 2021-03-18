run: output.o
	./output

output.o: i2c/i2c.o i2c/i2c.o bme280/bme280.o uartModBus/uart.o uartModBus/crc.o
	gcc uartModBus/crc.o bme280/bme280.o uartModBus/uart.o i2c/i2c.o main.c -o output -lwiringPi

i2c.o: i2c/i2c.c
	gcc i2c/i2c.c -o i2c/i2c.o -lwiringPi

bme280.o: bme280/bme280.c
	gcc bme280/bme280.c -o bme280/bme280.o

uart.o: uartModBus/uart.c
	gcc uartModBus/uart.c -o uartModBus/uart.o

crc.o: uartModBus/crc.c
	gcc uartModBus/crc.c -o uartModBus/crc.o

clear:
	rm ./*/*.o
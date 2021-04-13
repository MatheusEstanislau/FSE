output.o: bme280.o
	g++ binaries/* main.cpp -o output

bme280.o: createFolder
	gcc -c bme280/bme280.c -o binaries/bme280.o
	g++ -c bme280/bme-read-values.cpp -o binaries/bme.o

createFolder: bme280.o
	mkdir binaries

delete:
	rm -r binaries

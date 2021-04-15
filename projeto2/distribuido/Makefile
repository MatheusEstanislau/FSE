output.o: lampsController windowsController doorController bmeController
	g++ binaries/* server.cpp -o server.o -lwiringPi

bmeController:
	gcc -c controller/bme280/bme280.c -o binaries/bme280.o 
	g++ -c controller/bme280/bme280Controller.cpp binaries/bme280.o -o binaries/bme.o -lwiringPi

doorController:
	g++ -c controller/doors/doorsController.cpp -o binaries/doors.o

windowsController:
	g++ -c controller/windows/windowsController.cpp -o binaries/windows.o

lampsController:
	mkdir binaries
	g++ -c controller/lamps/lampsController.cpp -o binaries/lamps.o

bme280.o:
	gcc -c bme280/bme280.c -o binaries/bme280.o
	g++ -c bme280/bme-read-values.cpp -o binaries/bme.o

delete:
	rm output
	rm -r binaries


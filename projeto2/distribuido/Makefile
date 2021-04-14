output.o: lampsController windowsController doorController
	g++ binaries/* main.cpp -o output -lwiringPi

doorController:
	g++ -c controller/doors/doorsController.cpp -o binaries/doors.o

windowsController:
	g++ -c controller/windows/windowsController.cpp -o binaries/windows.o

lampsController:
	g++ -c controller/lamps/lampsController.cpp -o binaries/lamps.o

bme280.o: createFolder
	gcc -c bme280/bme280.c -o binaries/bme280.o
	g++ -c bme280/bme-read-values.cpp -o binaries/bme.o

# createFolder: lampsController
# 	mkdir binaries

delete:
	rm output
	rm -r binaries


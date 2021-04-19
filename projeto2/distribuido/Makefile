output.o: createFolder controllers
	g++ binaries/* src/main.cpp -o server.o -lwiringPi

controllers:
	g++ -c src/app/server/server.cpp -o binaries/socketServer.o
	g++ -c src/app/client/socketClient.cpp -o binaries/socketClient.o
	gcc -c src/controller/bme280/bme280.c -o binaries/bme280.o 
	g++ -c src/controller/bme280/bme280Controller.cpp -o binaries/bme.o
	g++ -c src/controller/doors/doorsController.cpp -o binaries/doors.o
	g++ -c src/controller/windows/windowsController.cpp -o binaries/windows.o
	g++ -c src/controller/airConditioner/airConditioner.cpp -o binaries/air.o
	g++ -c src/controller/lamps/lampsController.cpp -o binaries/lamps.o
	g++ -c src/controller/gpio/gpioController.cpp -o binaries/gpio.o
	g++ -c src/controller/presenceSensor/presenceSensorController.cpp -o binaries/presence.o

createFolder:
	if [ ! -f ./binaries/air.o ]; then \
		mkdir ./binaries; \
	fi

clean:
	if [ -f ./binaries/air.o ]; then \
		rm -r ./binaries; \
	fi
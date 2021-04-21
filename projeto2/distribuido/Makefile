output.o: createFolder controllers
	g++ obj/* src/main.cpp -o ./bin/dist.o -lwiringPi

controllers:
	g++ -c src/app/server/server.cpp -o obj/socketServer.o
	g++ -c src/app/client/socketClient.cpp -o obj/socketClient.o
	gcc -c src/controller/bme280/bme280.c -o obj/bme280.o 
	g++ -c src/controller/bme280/bme280Controller.cpp -o obj/bme.o
	g++ -c src/controller/doors/doorsController.cpp -o obj/doors.o
	g++ -c src/controller/windows/windowsController.cpp -o obj/windows.o
	g++ -c src/controller/airConditioner/airConditioner.cpp -o obj/air.o
	g++ -c src/controller/lamps/lampsController.cpp -o obj/lamps.o
	g++ -c src/controller/gpio/gpioController.cpp -o obj/gpio.o
	g++ -c src/controller/presenceSensor/presenceSensorController.cpp -o obj/presence.o

createFolder:
	if [ ! -f ./obj/air.o ]; then \
		mkdir ./obj; \
		mkdir ./bin; \
	fi

delete:
	if [ -f ./obj/air.o ]; then \
		rm -r ./obj; \
		rm -r ./bin; \
	fi
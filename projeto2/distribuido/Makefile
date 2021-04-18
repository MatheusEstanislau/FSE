output.o: createFolder lampsController windowsController doorController bmeController airConditionerController server gpioController
	g++ binaries/* src/main.cpp -o server.o -lwiringPi

server:
	g++ -c src/app/server/server.cpp -o binaries/socketServer.o
	g++ -c src/app/client/socketClient.cpp -o binaries/socketClient.o

bmeController:
	gcc -c src/controller/bme280/bme280.c -o binaries/bme280.o 
	g++ -c src/controller/bme280/bme280Controller.cpp -o binaries/bme.o

doorController:
	g++ -c src/controller/doors/doorsController.cpp -o binaries/doors.o

windowsController:
	g++ -c src/controller/windows/windowsController.cpp -o binaries/windows.o

airConditionerController:
	g++ -c src/controller/airConditioner/airConditioner.cpp -o binaries/air.o

lampsController:
	g++ -c src/controller/lamps/lampsController.cpp -o binaries/lamps.o

gpioController:
	g++ -c src/controller/gpio/gpioController.cpp -o binaries/gpio.o

createFolder:
	if [ ! -f ./binaries/air.o ]; then \
		mkdir ./binaries; \
	fi

clean:
	if [ -f ./binaries/air.o ]; then \
		rm -r ./binaries; \
	fi
output.o: createFolders menu server alarm
	g++ obj/* src/main.cpp -o bin/app -std=c++11 -pthread

menu:
	g++ -c src/menu/menu.cpp -o obj/menu.o

server:
	g++ -c src/clientSocket/server.cpp -o obj/client.o
	g++ -c src/serverSocket/serverSocket.cpp -o obj/server.o
	g++ -c src/createLogs/generateLog.cpp -o obj/log.o
	
alarm:
	g++ -c src/alarm/alarmHandler.cpp -o obj/alarm.o

createFolders:
	if [ ! -f ./bin/app ]; then \
		mkdir bin; \
		mkdir obj; \
	fi
	
delete:
	if [ -f ./inc/menu.o ]; then \
		rm -r bin; \
		rm -r obj; \
	fi
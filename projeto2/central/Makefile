output.o: menu server
	g++ binaries/* main.cpp -o output -pthread

menu:
	mkdir binaries
	g++ -c src/menu/menu.cpp -o binaries/menu.o

server:
	g++ -c src/server/server.cpp -o binaries/server.o

delete:
	rm output
	rm -r binaries
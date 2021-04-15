output.o: menu
	g++ binaries/* main.cpp -o output

menu:
	mkdir binaries
	g++ -c src/menu/menu.cpp -o binaries/menu.o

delete:
	rm output
	rm -r binaries
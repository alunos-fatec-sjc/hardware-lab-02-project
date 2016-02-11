compile:
	g++ -o program main.cpp
	chmod +x ./program

run: compile
	./program

debug:
	valgrind -v ./program


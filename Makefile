run: compile
	./program

compile:
	g++ -o program main.cpp
	chmod +x ./program

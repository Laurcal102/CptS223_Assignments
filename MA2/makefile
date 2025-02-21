all: mainexe

mainexe: main.o 
	g++ -std=c++11 -g -Wall main.o -o mainexe

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm main.o; rm mainexe
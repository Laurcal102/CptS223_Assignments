all: mainexe

mainexe: main.o GameWrapper.o
	g++ -std=c++11 -g -Wall main.o GameWrapper.o -o mainexe

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp  

GameWrapper.o: GameWrapper.cpp
	g++ -std=c++11 -g -Wall -c GameWrapper.cpp   

clean:
	rm main.o; rm GameWrapper.o; rm mainexe
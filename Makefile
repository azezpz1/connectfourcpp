all:./objects/main

./objects:
	mkdir ./objects

./objects/main.o: ./objects ./source/main.cpp
	g++ -c source/main.cpp -o $@

./objects/Board.o: ./objects ./source/Board.cpp
	g++ -c source/Board.cpp -o $@

./objects/main: objects/main.o objects/Board.o
	g++ -o $@ objects/main.o objects/Board.o

clean:
	rm -rf ./objects
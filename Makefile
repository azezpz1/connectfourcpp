all:./objects/main

./objects:
	mkdir ./objects

./objects/main: ./objects main.cpp
	g++ main.cpp -o objects/main

clean:
	rm -rf ./objects
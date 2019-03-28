all: main.cpp
	mkdir ./objects
	g++ main.cpp -o objects/main

clean:
	rm -rf ./objects
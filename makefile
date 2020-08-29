.DEFAULT_GOAL := all

all: clean build

build:
	g++ main.cpp quadratic.cpp
clean:
	rm ./a.out

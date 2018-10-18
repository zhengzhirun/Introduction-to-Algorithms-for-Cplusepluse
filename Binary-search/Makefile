cc = g++

VERSION = -std=c++0x

all: generateTestData test

generateTestData: generateTestData.cpp
	$(cc) $(VERSION) -o generateTestData  generateTestData.cpp

test: test.cpp binarySearch.h
	$(cc) $(VERSION) -o test test.cpp 

clean:
	rm binarySearch.o

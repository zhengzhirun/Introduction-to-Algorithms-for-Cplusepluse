# 选择g++编译器
c++ = g++

CFLAG = -std=c++0x

all: generateTestData Test

generateTestData: generateTestData.cpp
	$(c++) $(CFLAG) -o generateTestData generateTestData.cpp

Test: Test.cpp maxSubset.o
	$(c++) $(CFLAG) -o Test Test.cpp maxSubset.o

maxSubset.o: maxSubset.cpp maxSubset.h
	$(c++) $(CFLAG) -c maxSubset.cpp

clean:
	rm maxSubset.o

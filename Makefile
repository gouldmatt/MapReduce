#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -std=c++11

outputWord.o: host.o guestWordCount.o
	g++  -std=c++11 -pthread host.o guestWordCount.o -o output
	time ./outputWord

outputMatrix.o: host.o guestMatrixMultiply.o
	g++  -std=c++11 -pthread host.o guestMatrixMultiply.o -o outputMatrix
	time ./outputMatrix

host.o: host.cpp
	g++ -std=c++11 -pthread -c host.cpp

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -std=c++11 -pthread -c guestWordCount.cpp

guestMatrixMultiply.o: guestMatrixMultiply.cpp guestMatrixMultiply.hpp
	g++ -std=c++11 -pthread -c guestMatrixMultiply.cpp

clean:
	rm *.o output

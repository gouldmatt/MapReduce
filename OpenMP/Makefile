#target: dependencies
#	action

CFLAGS  = -Wall -std=c++11

output: host.o guestWordCount.o
	g++  -std=c++11 host.o guestWordCount.o -o output -fopenmp

host.o: host.cpp
	g++ -std=c++11 -c host.cpp -fopenmp

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -std=c++11 -c guestWordCount.cpp -fopenmp

clean:
	rm *.o output
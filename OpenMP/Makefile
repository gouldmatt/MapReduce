#target: dependencies
#	action

CFLAGS  = -Wall -std=c++11

output: host.o guestWordCount.o
	g++  -std=c++11 host.o guestWordCount.o -o output -fopenmp -lpthread
	./output

host.o: host.cpp
	g++ -std=c++11 -c host.cpp -fopenmp -lpthread

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -std=c++11 -c guestWordCount.cpp -fopenmp -lpthread

clean:
	rm *.o output
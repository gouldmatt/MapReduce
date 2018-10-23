#target: dependencies
#	action

CFLAGS  = -Wall -std=c++11

output: host.o guestWordCount.o
	g++ host.o guestWordCount.o -o output -Xpreprocessor -fopenmp -lomp
	./output

host.o: host.cpp
	g++ -c host.cpp -Xpreprocessor -fopenmp

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -c guestWordCount.cpp 

clean:
	rm *.o output
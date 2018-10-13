#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -std=c++11

output.o: host.o guestWordCount.o
	g++ host.o guestWordCount.o -o output
	time ./output

host.o: host.cpp
	g++ -c host.cpp

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -c guestWordCount.cpp

clean:
	rm *.o output

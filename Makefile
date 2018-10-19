#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -std=c++11

outputWord.o: host.o guestWordCount.o
	g++  -std=c++11 -pthread host.o guestWordCount.o -o output
	time ./outputWord

primes: host.o guestPrimeNumber.o host.cpp guestPrimeNumber.cpp guestPrimeNumber.hpp
	g++  -std=c++11 -pthread host.o guestPrimeNumber.o -o guestPrimeNumber
	time ./guestPrimeNumber

host.o: host.cpp
	g++ -std=c++11 -pthread -c host.cpp

guestWordCount.o: guestWordCount.cpp guestWordCount.hpp
	g++ -std=c++11 -pthread -c guestWordCount.cpp

guestPrimeNumber.o: guestPrimeNumber.cpp guestPrimeNumber.hpp
	g++ -std=c++11 -pthread -c guestPrimeNumber.cpp

clean:
	rm *.o output

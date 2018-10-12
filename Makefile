#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

output.o: wordCount.cpp
	g++  wordCount.cpp -std=c++11 -o output
	time ./output

clean:
	rm *.o output

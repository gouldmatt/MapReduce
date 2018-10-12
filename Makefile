#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

output.o: wordCount.cpp
	g++  wordCount.cpp -std=c++11 -pthread -o output
	time ./output
	#valgrind --tool=memcheck --leak-check=full ./output
	#valgrind --tool=helgrind ./output

clean:
	rm *.o output

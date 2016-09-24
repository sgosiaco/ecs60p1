a.out : timetest.o
	g++ -ansi -Wall -g -o a.out timetest.o

timetest.o : timetest.cpp
	g++ -ansi -Wall -g -c timetest.cpp

clean :
	rm -f a.out timetest.o

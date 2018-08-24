all: test_random

test_random: main.o mersenne-twister.o
	g++ main.o mersenne-twister.o -o test_random

main.o: main.cpp
	g++ -c main.cpp

mersenne-twister.o: mersenne-twister.cpp
	g++ -c mersenne-twister.cpp


clean:
	rm -rf *.o test_random

CC=g++
CC_FLAGS=-std=c++11

test: unit_test.o Image.o
	$(CC) -o test unit_test.o Image.o $(CC_FLAGS)

Image.o: ../Image.cpp ../Image.h
	$(CC) -c ../Image.cpp $(CC_FLAGS)

unit_test.o: unit_test.cpp unit_test.h
	$(CC) -c unit_test.cpp $(CC_FLAGS)

run:
	./test

clean:
	rm *.o test
CC=g++
CC_FLAGS=-std=c++11

imageops: driver.o Image.o
	$(CC) -o imageops driver.o Image.o $(CC_FLAGS)

Image.o: Image.cpp Image.h
	$(CC) -c -o Image.o Image.cpp $(CC_FLAGS)

driver.o: driver.cpp Image.h
	$(CC) -c -o driver.o driver.cpp $(CC_FLAGS)

run:
	./imageops

clean:
	rm *.o imageops
all: build prog testing

testing: build/test/test.o build/main/func.o
	gcc -Wall -Werror build/test/test.o build/main/func.o -o testing

prog: build/main/main.o build/main/func.o
	gcc -Wall -Werror build/main/main.o build/main/func.o -o prog

build/main/main.o: src/main.c src/func.h
	gcc -Wall -Werror -c src/main.c -o build/main/main.o

build/main/func.o: src/func.c src/func.h
	gcc -Wall -Werror -c src/func.c -o build/main/func.o

build/test/test.o: test/test.c src/func.h
	gcc -Wall -Werror -c test/test.c -o build/test/test.o

build:
	mkdir build
	mkdir build/test
	mkdir build/main


clean:
	rm -rf build main testing

gdb:
	gcc -Wall -O3 -g -o main src/main.c src/func.c

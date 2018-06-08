BTT = build/test/test.o
BMF = build/main/func.o
BMM = build/main/main.o
SM = src/main.c
SFH = src/func.h
SF = src/func.c
TT = test/test.c
all: build prog testing

testing: $(BTT) $(BMF)
	gcc -Wall -Werror build/test/test.o build/main/func.o -o testing

prog: $(BMM) $(BMF)
	gcc -Wall -Werror build/main/main.o build/main/func.o -o prog

build/main/main.o: $(SM) $(SFH)
	gcc -Wall -Werror -c src/main.c -o build/main/main.o

build/main/func.o: $(SF) $(SFH)
	gcc -Wall -Werror -c src/func.c -o build/main/func.o

build/test/test.o: $(TT) $(SFH)
	gcc -Wall -Werror -c test/test.c -o build/test/test.o

build:
	mkdir build
	mkdir build/test
	mkdir build/main

clean:
	rm -rf build prog testing

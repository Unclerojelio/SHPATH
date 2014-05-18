CC=g++
CFLAGS=-g -Wall

all: SHPATH

SHPATH: SHPATH.o
	 ${CC} -o SHPATH SHPATH.o

SHPATH.o: SHPATH.cpp
	 ${CC} -c ${CFLAGS} SHPATH.cpp
	 
run: SHPATH
	 ./SHPATH < SHPATH.in
     
clean:
	 rm *.o SHPATH core
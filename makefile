all: SHPATH

SHPATH: SHPATH.o
	 g++ -o SHPATH SHPATH.o

SHPATH.o: SHPATH.cpp
	 g++ -c -g SHPATH.cpp
	 
run: SHPATH
	 ./SHPATH < SHPATH.in
     
clean:
	 rm SHPATH.o SHPATH
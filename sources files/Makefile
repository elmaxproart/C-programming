CC = gcc
CFLAGS = -Wall

all: UNIX

UNIX: main_UNIX.c fonction_UNIX.c fonction_UNIX.h
	$(CC) -o UNIX main_UNIX.c fonction_UNIX.c

install:
	
	cp UNIX ~/Documents/UNIX.deb
	cp UNIX ~/Desktop/UNIX.exe
	cp UNIX ~/Desktop/UNIX.sh
run:
	./UNIX
	

clean:
	rm -f UNIX
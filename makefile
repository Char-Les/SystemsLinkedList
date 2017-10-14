all:
	gcc -o linked.exe linked.c linked.h

run: all
	./linked.exe

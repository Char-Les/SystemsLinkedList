all:
	gcc -o linked.e linked.c linked.h

run: all
	./linked.e

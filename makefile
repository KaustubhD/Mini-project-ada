CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

.PHONY: clean

test : test.c dijkstra.o floyd.o
	gcc $(CFLAGS) -o test dijkstra.o floyd.o test.c


dijkstra.o : floyd.o dijkstra.h dijkstra.c
	gcc $(CFLAGS) -c dijkstra.c

floyd.o : floyd.c floyd.h
	gcc $(CFLAGS) -c floyd.c

clean :
	rm -f *.o  *~ ll test
	rm -rf *.dSYM
all: sort

sort: sort.o
	gcc -o sort sort.c

clean:
	rm -rf *.o sort

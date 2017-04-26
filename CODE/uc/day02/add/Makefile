add:main.o add.o
	cc main.o add.o -o add
main.o:main.c
	cc -c main.c -I ..
add.o:add.c
	cc -c add.c	 -I ..
clean:
	rm *.o add

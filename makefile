compile: list.c
	gcc -o list list.c

run: list
	./list

clean:
	rm list
	rm *~

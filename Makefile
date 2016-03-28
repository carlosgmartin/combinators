all: main

main: main.o tree.o list.o eval.o enum.o
	gcc main.o tree.o list.o eval.o enum.o -o main

enum.o: enum.c
	gcc -c enum.c

main.o: main.c
	gcc -c main.c

tree.o: tree.c
	gcc -c tree.c

list.o: list.c
	gcc -c list.c

eval.o: eval.c
	gcc -c eval.c

.PHONY: clean
clean:
	rm -f *.o main
	find . -name "main *" -exec rm {} \;

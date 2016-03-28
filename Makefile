all: main

main: main.o tree.o list.o eval.o
	gcc main.o tree.o list.o eval.o -o main

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

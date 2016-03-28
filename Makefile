all: combinators

combinators: combinators.o tree.o list.o
	gcc combinators.o tree.o list.o -o combinators

combinators.o: combinators.c
	gcc -c combinators.c

tree.o: tree.c list.o
	gcc -c tree.c

list.o: list.c
	gcc -c list.c

.PHONY: clean
clean:
	rm -f *.o combinators
	find . -name "combinators *" -exec rm {} \;

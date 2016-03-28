all: combinators

combinators: combinators.o tree.o
	gcc combinators.o tree.o -o combinators

combinators.o: combinators.c
	gcc -c combinators.c

tree.o: tree.c
	gcc -c tree.c

.PHONY: clean
clean:
	rm -f *.o combinators
	find . -name "combinators *" -exec rm {} \;

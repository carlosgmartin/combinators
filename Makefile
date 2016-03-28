all: combinators

combinators: combinators.o tree.o list.o eval.o
	gcc combinators.o tree.o list.o eval.o -o combinators

combinators.o: combinators.c
	gcc -c combinators.c

tree.o: tree.c
	gcc -c tree.c

list.o: list.c
	gcc -c list.c

eval.o: eval.c
	gcc -c eval.c

.PHONY: clean
clean:
	rm -f *.o combinators
	find . -name "combinators *" -exec rm {} \;

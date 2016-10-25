main: lex.o
	gcc main.c -o main ./lex.o

lex.o: lex.c
	gcc -c lex.c

clean:
	rm lex.o main
	
run: main
	./main ./sample.c

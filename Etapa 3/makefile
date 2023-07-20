#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#
etapa2: y.tab.o lex.yy.o hashtable.o ast.o main.o
	gcc -o etapa3 y.tab.o lex.yy.o hashtable.o ast.o main.o

main.o: main.c
	gcc -c main.c

hashtable.o: hashtable.c
	gcc -c hashtable.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	flex scanner.l

clean:
	rm *.o lex.yy.c y.tab.c etapa3 y.output
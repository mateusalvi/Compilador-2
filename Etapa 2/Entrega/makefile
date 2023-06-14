#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa2: lex.yy.c hashtable.c scanner.l parser.y main.c parser.tab.o
	gcc -c lex.yy.c main.c parser.tab.c
	gcc -o etapa2 main.c lex.yy.o hashtable.c parser.tab.o -lfl
	
lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c: parser.y
	bison -v parser.y

clean:
	rm lex.yy.c parser.tab.c parser.tab.o lex.yy.o etapa2 parser.output main.o

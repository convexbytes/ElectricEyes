CC 			= g++
CFLAGS 		= -g -Wall
LDFLAGS 	= 
LDLIBS 		= -lfl 

all: client_parser.tab.o client_parser_driver.o lex.yy.o

lex.yy.o: lex.yy.c client_lexer.h
	$(CC) -c $(LDFLAGS) lex.yy.c -o $@

lex.yy.c: client_lexer.l
	flex  --header-file=client_lexer.h client_lexer.l

client_lexer.h: client_lexer.l
	flex --header-file=client_lexer.h client_lexer.l

client_parser.tab.o: client_parser.tab.cc client_parser.tab.hh client_lexer.h
	$(CC) -c $(LDFLAGS) client_parser.tab.cc -o $@

client_parser.tab.cc: client_parser.y
	bison -d client_parser.y

client_parser.tab.hh: client_parser.y
	bison -d client_parser.y

client_parser_driver.o: client_parser_driver.cpp client_parser_driver.h 
	$(CC) -c client_parser_driver.cpp -o $@

clean:
	rm lex.yy.c client_lexer.h client_parser.tab.cc client_parser.tab.hh position.hh stack.hh location.hh

.PHONY: clean
# 
# Makefile
# 
# Created by Michael Dickens on 1/26/2013.
# 

flags = -Wall -std=gnu++11

sources = main.cpp exceptions.cpp token.cpp lexer.cpp parser.cpp

all : $(sources)
	g++ $(sources) $(flags) -O0 -g

release : $(sources)
	g++ $(sources) $(flags) -O2

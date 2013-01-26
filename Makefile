# 
# Makefile
# 
# Created by Michael Dickens on 1/26/2013.
# 

flags = -Wall

sources = main.cpp Exceptions.cpp Lexer.cpp Parser.cpp

all : $(sources)
	g++ $(sources) $(flags) -O0 -g

release : $(sources)
	g++ $(sources) $(flags) -O2

# 
# Makefile
# 
# Created by Michael Dickens on 1/26/2013.
# 

flags = -Wall -std=c++11

debug_flags = -O0 -g

release_flags = -02

sources = main.cpp exceptions.cpp token.cpp lexer.cpp parser.cpp

# Compile in debug mode.
all : $(sources)
	g++ $(sources) $(flags) $(debug_flags)

# Compile for profiling with gprof. Uses release flags.
profile : $(sources)
	g++ $(sources) $(flags) $(release_flags) -pg

# Compile in release mode.
release : $(sources)
	g++ $(sources) $(flags) $(release_flags)

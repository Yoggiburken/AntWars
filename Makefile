## Variables ##
CC=g++
CPPFLAGS=-g -Wall
CPPLIBS=-lsfml-graphics -lsfml-window -lsfml-system
.SUFFIXES: .cpp

.cpp.o:
	g++ $(CPPFLAGS) -c $<

## Targets ##

all: AntWars other


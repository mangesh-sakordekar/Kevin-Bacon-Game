# Makefile for Bacon Number  application

# Class:  CSC 315 Data Structures & Algorithms
# Date:   Spring 2018

# C++ compiler flags
#CXXFLAGS = -Wall -O2 -fmax-errors=5 -std=c++11

CFLAGS += -O -Wall -fmax-errors=5
CXXFLAGS += $(CFLAGS) -std=c++11

# targets:
bacon:	main.o readbin.o bfs.o stats.o search.o
	g++ -o $@ $^



clean:
	rm -f *.o

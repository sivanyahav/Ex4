CC=gcc
AR=ar
FLAGS= -Wall -g


all: frequency

frequency: main.o trie.o
	$(CC) $(FLAGS) main.o trie.o -o frequency

main.o: main.c trie.h 
	$(CC) $(FLAGS) -c main.c

trie.o: trie.c  trie.h
	$(CC) $(FLAGS) -c trie.c



.PHONY: clean all frequency

clean: 
	rm -f frequency *.o
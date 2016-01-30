CC=clang
CFLAGS=-o3 -std=c99 -Wall -pedantic
EXT=''

all: compile
	@echo [run]
	./run
	
compile:
	clear
	@echo [compile]
	$(CC) $(CFLAGS) zad$(CODE).c -o run $(EXT)

clean:
	@echo [clean]
	rm ./run

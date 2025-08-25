CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS =
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
EXEC = block-of-life

all: $(EXEC)

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

clean:
	rm -rf build $(EXEC)

install: $(EXEC)
	mkdir -p $(CURDIR)/debian/block-of-life/usr/games
	cp $(EXEC) $(CURDIR)/debian/block-of-life/usr/games/


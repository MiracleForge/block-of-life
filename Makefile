CC = gcc
CFLAGS = -Wall -g
LDFLAGS =
SRC = src/block_of_life.c
OBJ = $(SRC:.c=.o)
EXEC = block-of-life

all: $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

install: $(EXEC)
	mkdir -p $(CURDIR)/debian/block-of-life/usr/games
	cp $(EXEC) $(CURDIR)/debian/block-of-life/usr/games/


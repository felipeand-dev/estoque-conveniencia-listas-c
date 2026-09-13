CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

estoque: main.c produtos.c somples/simples.c dupla/dupla.c circular/circular.c
	$(CC) $(CFLAGS) main.c produtos.c somples/simples.c dupla/dupla.c circular/circular.c -o estoque

clean:
	rm -f estoque *.o

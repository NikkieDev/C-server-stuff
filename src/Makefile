cc = gcc
CFLAGS = -Wall -Wextra -std=c99

all: clean server client

server: ./server/*.c
	${CC} ${CFLAGS} ./server/*.c -o ../out/server

client: ./client/*.c
	${CC} ${CFLAGS} ./client/*.c -o ../out/client

clean: cleanserver cleanclient

cleanserver:
	rm -f ../out/server

cleanclient:
	rm -f ../out/client

clearconsole:
	clear
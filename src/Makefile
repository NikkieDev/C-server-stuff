cc = gcc
CFLAGS = -Wall -Wextra -std=c99

all: clean server client clearconsole

server: ./server/*.c
	${CC} ${CFLAGS} -o ../out/server ./server/*.c

client: ./client/*.c
	${CC} ${CFLAGS} -o ../out/client ./client/*.c

clean: cleanserver cleanclient

cleanserver:
	rm -f ../out/server

cleanclient:
	rm -f ../out/client

clearconsole:
	clear
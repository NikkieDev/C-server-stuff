cc = gcc
CFLAGS = -Wall -Wextra -std=c99

all: clean server client

server: ./src/server/*.c
	${CC} ${CFLAGS} ./src/server/*.c -o ./out/server

client: ./src/client/*.c
	${CC} ${CFLAGS} ./src/client/*.c -o ./out/client

clean: cleanserver cleanclient

cleanserver:
	rm -f ./out/server

cleanclient:
	rm -f ./out/client

runserver:
	./out/server
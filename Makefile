CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o readMap.o generateMap.o game.o terminal.o snake.o linkedList.o undo.o
EXEC = maze

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c generateMap.h game.h terminal.h snake.h linkedList.h undo.h
	$(CC) $(CFLAGS) main.c -g -c

readMap.o: readMap.c readMap.h
	$(CC) $(CFLAGS) readMap.c -c 

generateMap.o: generateMap.c generateMap.h game.h
	$(CC) $(CFLAGS) generateMap.c -c

game.o: game.c game.h
	$(CC) $(CFLAGS)  game.c -c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

snake.o: snake.c snake.h game.h
	$(CC) $(CFLAGS) snake.c -c

linkedList.o: linkedList.c linkedList.h undo.h
	$(CC) $(CFLAGS) linkedList.c -c

undo.o: undo.c undo.h linkedList.h game.h
	$(CC) $(CFLAGS) undo.c -c

clean:
	rm -f $(EXEC) $(OBJ)

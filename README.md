# New features
- Players can now undo their moves to get out of sticky situations.
- Added a non player character (snake) which tries to intercept the player before reaching the goal.

# Deprecated features
- Ability to set map visibility.

# Files required to run program 
- main.c 
- game.c game.h
- generateMap.c generateMap.h 
- linked.c linked.h
- readMap.c readMap.h 
- snake.c snake.h
- terminal.c terminal.h 
- undo.c undo.h 
- MakeFile
- map.txt (alternate file can be provided)
(NOTE: All files must be in the same directory before compiling!)

# Dependencies
- main.c - <stdio.h> <stdlib.h> "readMap.h" "generateMap.h" "game.h" "terminal.h" "snake.h" "linkedList.h" "undo.h"
- game.c - <stdio.h> "game.h"
- generateMap.c - <stdio.h> "generateMap.h" "game.h"
- linkedList.c - <stdio.h> <stdlib.h> "linkedList.h" "undo.h"
- readMap.c - <stdio.h> <stdlib.h> "readMap.h>
- snake.c - <stdio.h> "snake.h" "game.h"
- terminal.c - <stdio.h> <termios.h> "terminal.h"
- undo.c - <stdio.h> "linkedList.h" "undo.h" "game.h"

# How to run program
Step1: Run Makefile by typing ‘make’ in terminal (cd into the program directory first)
Make file will create an executable called maze
Step3: Provide the name of the text file containing the metadata as command line argument eg: ./maze map.txt
Step4: Play Game!

NOTE: Running "make DEBUG=1" will enable debug stats while playing the game. This mode is used fo debugging and testing.

#ifndef GAME_H
#define GAME_H

#define WALL 'o'
#define GOAL 'x'
#define SNAKE '~'
#define PLAYERUP '^'
#define PLAYERDOWN 'v'
#define PLAYERLEFT '<'
#define PLAYERRIGHT '>'
#define BLANK ' '

#define UNDO 'u'

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define RUNNING 1
#define LOST 0
#define WON 2

#define TOP_BORDER 0
#define LEFT_BORDER 0

void updatePlayer(char **map, int mapRow, int mapCol, int *playerPos, int *goalPos, char input);
void moveUp(char **map, int *playerPosR, int *playerPosC);
void moveDown(char **map, int *playerPosR, int *playerPosC, int maxRowBorder);
void moveRight(char **map, int *playerPosR, int *playerPosC, int maxColBorder);
void moveLeft(char **map, int *playerPosR, int *playerPosC);

#endif
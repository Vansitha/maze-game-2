#ifndef SNAKE_H
#define SNAKE_H

#define FALSE 0
#define TRUE !FALSE

void updateSnake(char **map, int mapRow, int mapCol, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC);
#endif
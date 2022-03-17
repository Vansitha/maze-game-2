#include <stdio.h>
#include "linkedList.h"
#include "undo.h"
#include "game.h"

void convertData(void *data, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC, char *playerDir, char input)
{
    /* NAME: convertData
       PURPOSE: convert void data from linked list to user (programmer) defined data type --> Coordinates
       IMPORTS: data, playerPosR, playerPosC, snakePosR, snakePosC, playerDir, input
       EXPORTS: None
       ASSERTIONS:
           PRE: linked list must be initialized and contain data
           POST: Update object positions
    */

    if (data != NULL)
    {
        Coordinates *positions;
        positions = (Coordinates *)(data);

        *playerPosR = positions->playerPosR;
        *playerPosC = positions->playerPosC;
        *snakePosR = positions->snakePosR;
        *snakePosC = positions->snakePosC;
        *playerDir = positions->charDirection;
    }
}

void revertMap(char **map, int mapRow, int mapCol, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC, char *playerDir)
{
    /* NAME: revertMap
       PURPOSE: Reverts object locations (snake and player) based on the previous coordinates
       IMPORTS: map, mapRow, mapCol, playerPosR, playerPosC, snakePosR, snakePosc, playerDir
       EXPORTS: None
       ASSERTIONS:
           PRE: Map must be created
           POST: Updated Map with previous object position
    */
    int r;
    int c;

    for (r = 0; r < mapRow; r++)
    {
        for (c = 0; c < mapCol; c++)
        {
            if (map[r][c] == SNAKE)
            {
                map[r][c] = BLANK;
                map[*snakePosR][*snakePosC] = SNAKE;
            }
            if (map[r][c] == PLAYERUP)
            {
                map[r][c] = BLANK;
                map[*playerPosR][*playerPosC] = *playerDir;
            }
            if (map[r][c] == PLAYERDOWN)
            {
                map[r][c] = BLANK;
                map[*playerPosR][*playerPosC] = *playerDir;
            }
            if (map[r][c] == PLAYERRIGHT)
            {
                map[r][c] = BLANK;
                map[*playerPosR][*playerPosC] = *playerDir;
            }
            if (map[r][c] == PLAYERLEFT)
            {
                map[r][c] = BLANK;
                map[*playerPosR][*playerPosC] = *playerDir;
            }
        }
    }
}

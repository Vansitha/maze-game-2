#include <stdio.h>
#include "game.h"

void updatePlayer(char **map, int mapRow, int mapCol, int *currPlayerPosR, int *currPlayerPosC, char input)
{
    /*
    NAME: updateMap
    PURPOSE: Updates player positon on map based input
    IMPORTS: map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, input
    EXPORTS: NONE
    ASSERTIONS:
        PRE: Get keyboard input, game map created and player postion known
        POST: Updates map in main.c with new player location
    */

    int maxRowBorder;
    int maxColBorder;

    /* NOTE: First column and row borders are always = 0 (constant)
             Defined in game.h as TOP_BORDER and LEFT_BORDER
    Maximum row and column borders are set based on map size. Arrays are 0
    based index therefore - 1 */
    maxRowBorder = mapRow - 1;
    maxColBorder = mapCol - 1;

    switch (input)
    {
    case UP:
    {
        moveUp(map, currPlayerPosR, currPlayerPosC);
        break;
    }
    case DOWN:
    {
        moveDown(map, currPlayerPosR, currPlayerPosC, maxRowBorder);
        break;
    }
    case LEFT:
    {
        moveLeft(map, currPlayerPosR, currPlayerPosC);
        break;
    }
    case RIGHT:
    {
        moveRight(map, currPlayerPosR, currPlayerPosC, maxColBorder);
        break;
    }
    }
}

void moveUp(char **map, int *playerPosR, int *playerPosC)
{
    if ((map[*playerPosR - 1][*playerPosC] != WALL) && (*playerPosR - 1 != TOP_BORDER))
    {
        map[*playerPosR][*playerPosC] = BLANK;
        map[*playerPosR - 1][*playerPosC] = PLAYERUP;
        *playerPosR = *playerPosR - 1;
    }
    else
    {
        map[*playerPosR][*playerPosC] = PLAYERUP;
    }
}

void moveDown(char **map, int *playerPosR, int *playerPosC, int maxRowBorder)
{
    if ((map[*playerPosR + 1][*playerPosC] != WALL) && (*playerPosR + 1 != maxRowBorder))
    {
        map[*playerPosR][*playerPosC] = BLANK;
        map[*playerPosR + 1][*playerPosC] = PLAYERDOWN;
        *playerPosR = *playerPosR + 1;
    }
    else
    {
        map[*playerPosR][*playerPosC] = PLAYERDOWN;
    }
}

void moveRight(char **map, int *playerPosR, int *playerPosC, int maxColBorder)
{
    if ((map[*playerPosR][*playerPosC + 1] != WALL) && (*playerPosC + 1 != maxColBorder))
    {
        map[*playerPosR][*playerPosC] = BLANK;
        map[*playerPosR][*playerPosC + 1] = PLAYERRIGHT;
        *playerPosC = *playerPosC + 1;
    }
    else
    {
        map[*playerPosR][*playerPosC] = PLAYERRIGHT;
    }
}

void moveLeft(char **map, int *playerPosR, int *playerPosC)
{
    if ((map[*playerPosR][*playerPosC - 1] != WALL) && (*playerPosC - 1 != LEFT_BORDER))
    {
        map[*playerPosR][*playerPosC] = BLANK;
        map[*playerPosR][*playerPosC - 1] = PLAYERLEFT;
        *playerPosC = *playerPosC - 1;
    }
    else
    {
        map[*playerPosR][*playerPosC] = PLAYERLEFT;
    }
}

#include <stdio.h>
#include "snake.h"
#include "game.h"

void updateSnake(char **map, int mapRow, int mapCol, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC)
{
    /* NAME: updateSnake
       PURPOSE: Responsible for moving non player character (snake) around the map to intercept player
       IMPORTS: map, mapRow, mapCol, playerPosR, playerPosC, snakePosR, snakePosC
       EXPORTS: none
       ASSERTIONS:
           PRE: metaDataTable must be created
           POST: Snake moves on map based on player location
    */

    int maxRowBorder = mapRow - 1;
    int maxColBorder = mapCol - 1;

    if (*playerPosR > *snakePosR)
    {
        if ((map[*snakePosR + 1][*snakePosC] != WALL) && (*snakePosR + 1 != maxRowBorder))
            if ((map[*snakePosR + 1][*snakePosC] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR + 1][*snakePosC] = SNAKE;
                *snakePosR = *snakePosR + 1;
            }
    }
    else if (*playerPosR < *snakePosR)
    {
        if ((map[*snakePosR - 1][*snakePosC] != WALL) && (*snakePosR - 1 != TOP_BORDER))
            if ((map[*snakePosR - 1][*snakePosC] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR - 1][*snakePosC] = SNAKE;
                *snakePosR = *snakePosR - 1;
            }
    }
    else if (*playerPosC > *snakePosC)
    {
        if ((map[*snakePosR][*snakePosC + 1] != WALL) && (*snakePosC + 1 != maxColBorder))
            if ((map[*snakePosR + 1][*snakePosC] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR][*snakePosC + 1] = SNAKE;
                *snakePosC = *snakePosC + 1;
            }
    }
    else if (*playerPosC < *snakePosC)
    {
        if ((map[*snakePosR][*snakePosC - 1] != WALL) && (*snakePosC - 1 != LEFT_BORDER))
            if ((map[*snakePosR][*snakePosC - 1] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR][*snakePosC - 1] = SNAKE;
                *snakePosC = *snakePosC - 1;
            }
    }
    else if ((*playerPosR == *snakePosR) && (*playerPosC > *snakePosR))
    {

        if ((map[*snakePosR][*snakePosC + 1] != WALL) && (*snakePosC + 1 != maxColBorder))
            if ((map[*snakePosR][*snakePosC + 1] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR][*snakePosC + 1] = SNAKE;
                *snakePosC = *snakePosC + 1;
            }
    }

    /* If the player is next to the snake eg: " ~< " during the next move when the player moves
           to the left the snake will move right which will cause the characters to cross the output
           will be "<~" therefore the snake would not catch the player. This if checks makes the snake
           guess the players next move. if the player tries to goes right again the snake will intercept
           the player at its new position and the player loses. This is done for doth left and right directions.
    */
    if ((map[*playerPosR][*playerPosC] == PLAYERLEFT) && (*playerPosR == *snakePosR) && ((*playerPosC - *snakePosC) == 1))
    {
        if ((map[*snakePosR][*snakePosC - 1] != WALL) && (*snakePosC - 1 != LEFT_BORDER))
        {
            if ((map[*snakePosR][*snakePosC - 1] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR][*snakePosC - 1] = SNAKE;
                *snakePosC = *snakePosC - 1;
            }
        }
    }
    if ((map[*playerPosR][*playerPosC] == PLAYERLEFT) && (*playerPosR == *snakePosR) && ((*snakePosC - *playerPosC) == 1))
    {
        if ((map[*snakePosR][*snakePosC + 1] != WALL) && (*snakePosC + 1 != LEFT_BORDER))
        {
            if ((map[*snakePosR][*snakePosC + 1] != GOAL))
            {
                map[*snakePosR][*snakePosC] = BLANK;
                map[*snakePosR][*snakePosC + 1] = SNAKE;
                *snakePosC = *snakePosC + 1;
            }
        }
    }
}

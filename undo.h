#ifndef UNDO_H
#define UNDO_H

/* Sample data structure */
typedef struct Coordinates
{
    int playerPosR;
    int playerPosC;

    int snakePosR;
    int snakePosC;

    char charDirection;

} Coordinates;

void convertData(void *data, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC, char *playerDir, char input);
void revertMap(char **map, int mapRow, int mapCol, int *playerPosR, int *playerPosC, int *snakePosR, int *snakePosC, char *playerDir);

#endif
#include <stdio.h>
#include "generateMap.h"
#include "game.h"

void createMap(char **map, int **metadataTable, int mapRow, int mapCol, int metadataAmount)
{
	/*
	NAME: createMap
	PURPOSE: Create the game map according to the data from the metadataTable
	IMPORTS: map, metadataTable, mapRow, mapCol, metadataAmount
	EXPORTS: NONE
	ASSERTIONS:
		PRE: main.c successfully extracts data from metadataTable
		POST: Fills char array(map) in main.c with game characters
	*/

	/* r and c represents current row and column */
	int row;
	int col;

	int maxRow;
	int maxCol;

	int tableCol;

	/* Metadata table has 3 columns */
	tableCol = 3;

	/* Maximum row and maximum column depending on the map size */
	maxRow = mapRow - 1;
	maxCol = mapCol - 1;

	/* Create the map border */
	for (row = 0; row < mapRow; row++)
	{
		for (col = 0; col < mapCol; col++)
		{
			if ((col >= 0) && (col <= maxCol) && ((row == 0) || (row == maxRow)))
			{
				map[row][col] = '-';
			}
			else if ((row >= 0) && (row < maxRow) && ((col == 0) || (col == maxCol)))
			{
				map[row][col] = '|';
			}
			else
			{
				map[row][col] = ' ';
			}
		}
	}
	/* replace the characters in the four corners of the map array to "#" */
	map[0][0] = '#';
	map[0][maxCol] = '#';
	map[maxRow][0] = '#';
	map[maxRow][maxCol] = '#';

	for (row = 0; row < metadataAmount; row++)
	{
		for (col = 0; col < tableCol; col++)
		{
			if (metadataTable[row][2] == 0)
			{
				map[metadataTable[row][0]][metadataTable[row][1]] = PLAYERUP;
			}

			if (metadataTable[row][2] == 1)
			{
				map[metadataTable[row][0]][metadataTable[row][1]] = SNAKE;
			}

			if (metadataTable[row][2] == 2)
			{
				map[metadataTable[row][0]][metadataTable[row][1]] = GOAL;
			}
			if (metadataTable[row][2] == 3)
			{
				map[metadataTable[row][0]][metadataTable[row][1]] = WALL;
			}
		}
	}
}

void displayMap(char **map, int mapRow, int mapCol)
{
	int r;
	int c;

	for (r = 0; r < mapRow; r++)
	{
		for (c = 0; c < mapCol; c++)
		{
			printf("%c", map[r][c]);
		}
		printf("\n");
	}
}
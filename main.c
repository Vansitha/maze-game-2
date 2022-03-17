#include <stdio.h>
#include <stdlib.h>
#include "readMap.h"
#include "generateMap.h"
#include "game.h"
#include "terminal.h"
#include "snake.h"
#include "linkedList.h"
#include "undo.h"

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int metadataAmount;
	int mapRow;
	int mapCol;
	int **metadataTable;
	/* Array declared to hold game map */
	char **map;
	char userInput;
	/* Variables will hold the postion of the player, goal and snake.
	 NOTE: Assumption of only 1 player goal and snake considered */
	int initialPlayerPosR;
	int initialPlayerPosC;
	int goalR;
	int goalC;
	int intitialSnakePosR;
	int initialSnakePosC;
	int *currPlayerPosR;
	int *currPlayerPosC;
	int *currSnakePosR;
	int *currSnakePosC;
	int i;				  /* index used in all the for loops below */
	int status;			  /* Game Status can be RUNNING, LOST or WON */
	LinkedList *ll;		  /*  linked list */
	Coordinates *dataSet; /*  struct to hold positions of player and snake */
	void *undoData;

	if (argc > 2)
	{
		printf("Too many arguments!\n");
	}
	else if (filename == NULL)
	{
		printf("Cannot create map without file!\n");
	}
	else
	{
		FILE *testOpen = fopen(filename, "r");
		if (testOpen == NULL)
		{
			perror("File Does not exist!");
		}
		else
		{
			fclose(testOpen);
			testOpen = NULL;
			/* Read meta data from file */
			readMetaData(filename, &metadataTable, &metadataAmount, &mapRow, &mapCol);

			/* Create empty 2d array to store characters */
			map = (char **)malloc(sizeof(char *) * mapRow);
			for (i = 0; i < mapRow; i++)
			{
				map[i] = (char *)malloc(sizeof(char) * mapCol);
			}

			/* Creates the maze map using the metadata */
			createMap(map, metadataTable, mapRow, mapCol, metadataAmount);

			for (i = 0; i < metadataAmount; i++)
			{
				if (metadataTable[i][2] == 0)
				{
					initialPlayerPosR = metadataTable[i][0];
					initialPlayerPosC = metadataTable[i][1];
				}
				if (metadataTable[i][2] == 1)
				{
					intitialSnakePosR = metadataTable[i][0];
					initialSnakePosC = metadataTable[i][1];
				}
				if (metadataTable[i][2] == 2)
				{
					goalR = metadataTable[i][0];
					goalC = metadataTable[i][1];
				}
			}

			/* Player, snake and goal location (row and column) on map */

			/* Current player position pointers (row and column) points to initial
			   position. This updates when the player moves around the map */
			currPlayerPosR = &initialPlayerPosR;
			currPlayerPosC = &initialPlayerPosC;
			currSnakePosR = &intitialSnakePosR;
			currSnakePosC = &initialSnakePosC;

			/* Free metadataTable from heap memory after extracting data to generate
			   map */
			for (i = 0; i < metadataAmount; i++)
			{
				free(metadataTable[i]);
			}
			free(metadataTable);
			metadataTable = NULL;

			ll = createLinkedList(); /* initialize linked list before starting the game */

			/* display the game map after creating map */
			displayMap(map, mapRow, mapCol);
			disableBuffer();

			/* MAIN GAME LOOP: Runs while player reaches the target and does not meet snake position*/
			status = RUNNING;
			while (status == RUNNING)
			{
				char *playerDir;
				char playerCharacter = map[*currPlayerPosR][*currPlayerPosC];
				playerDir = &playerCharacter;

				scanf("%c", &userInput);
				/* Handles the input and updates the players location in the map */

				/* Undo feature works on if user presses u key */
				if (userInput == UNDO)
				{
					if (ll->head != NULL)
					{
						undoData = removeFirst(ll);
						convertData(undoData, currPlayerPosR, currPlayerPosC, currSnakePosR, currSnakePosC, playerDir, userInput); /* convert void data to int data */
						revertMap(map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, currSnakePosR, currSnakePosC, playerDir);   /* updates the revert changes in the map */
						free(undoData);
						undoData = NULL;
					}
					if (ll->head != NULL)
					{
						undoData = removeFirst(ll);
						convertData(undoData, currPlayerPosR, currPlayerPosC, currSnakePosR, currSnakePosC, playerDir, userInput); /* convert void data to int data */
						revertMap(map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, currSnakePosR, currSnakePosC, playerDir);   /* updates the revert changes in the map */
						free(undoData);
						undoData = NULL;
					}
				}

				dataSet = (Coordinates *)malloc(sizeof(Coordinates));

				dataSet->playerPosR = *currPlayerPosR;
				dataSet->playerPosC = *currPlayerPosC;
				dataSet->snakePosR = *currSnakePosR;
				dataSet->snakePosC = *currSnakePosC;
				dataSet->charDirection = *playerDir;

				insertFirst(ll, dataSet);
				updatePlayer(map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, userInput);

				if (userInput == UP || userInput == DOWN || userInput == LEFT || userInput == RIGHT)
				{
					updateSnake(map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, currSnakePosR, currSnakePosC);
				}

				if (map[*currPlayerPosR][*currPlayerPosC] == map[*currSnakePosR][*currSnakePosC])
				{
					status = LOST;
				}
				else if ((map[*currPlayerPosR][*currPlayerPosC]) == (map[goalR][goalC]))
				{
					status = WON;
				}

				system("clear");
				displayMap(map, mapRow, mapCol);

/* For debugging/testing */
#ifdef DEBUG
				printf("\n===== Current Position Stats =====\n");
				printf("PlayerPosR: %d | PlayerPosC: %d\n", *currPlayerPosR, *currPlayerPosC);
				printf("Player: %c\n", map[*currPlayerPosR][*currPlayerPosC]);
				printf("SnakePosR: %d | SnakePosC: %d\n", *currSnakePosR, *currSnakePosC);
				printf("Snake: %c\n", map[*currSnakePosR][*currSnakePosC]);
				printf("======================================");
				printf("\n===== Previous Position Stats =====\n");
				printf("PlayerPosR: %d | PlayerPosC: %d\n", dataSet->playerPosR, dataSet->playerPosC);
				printf("SnakePosR: %d | SnakePosC: %d\n", dataSet->snakePosR, dataSet->snakePosR);
				printf("Player Character: %c\n", dataSet->charDirection);

#endif
			}
			/* END OF GAME */
			if (status == WON)
			{
				printf("\nYou Won!\n");
			}
			else
			{
				printf("\nYou Lost!\n");
			}
			enableBuffer();

			/* Free game map from heap memory after game ends */
			for (i = 0; i < mapRow; i++)
			{
				free(map[i]);
			}
			free(map);
			map = NULL;

			/* Free linked list */
			freeLinkedList(ll, freeData);
			free(ll);
			ll = NULL;
		}
	}
	return 0;
}

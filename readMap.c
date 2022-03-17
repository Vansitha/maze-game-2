#include <stdio.h>
#include <stdlib.h>
#include "readMap.h"

void readMetaData(char *filename, int ***metaDataTable, int *metaDataAmount, int *mapRow, int *mapCol)
{
    /* NAME: readMetaData
       PURPOSE: Extracts metadata from a file and stores in a 2d array
       IMPORTS: filename, metadataTable, metaDataAmount, mapRow, mapCol
       EXPORTS: None
       ASSERTIONS:
           PRE: File to the read must exist in program directory
           POST: metaDataTable is ready to create game map
    */
    FILE *fileRead = fopen(filename, "r");

    /* Already checked file in main.c (additional check)*/
    if (fileRead == NULL)
    {
        perror("Could not open file!");
    }
    else
    {
        int objectRow;
        int objectCol;
        int objectCode;
        int **table;
        int i;

        int done = FALSE;
        int tableCol = 3;

        /* read first line to know the size of the array we need */
        int firstLine;
        firstLine = fscanf(fileRead, "%d %d %d\n", metaDataAmount, mapRow, mapCol);

        /* Create array to store the positions from the txt file */
        table = (int **)malloc(sizeof(int *) * (*metaDataAmount));

        for (i = 0; i < (*metaDataAmount); i++)
        {
            table[i] = (int *)malloc(sizeof(int) * tableCol);
        }

        if (firstLine != EOF)
        {
            /* Read the rest of the data and store in array */
            int row = 0;
            while (!done)
            {
                int nRead;
                nRead = fscanf(fileRead, "%d %d %d\n", &objectRow, &objectCol, &objectCode);

                if (nRead != EOF)
                {
                    /* loop through the empty table and insert the values from the text file */
                    table[row][0] = objectRow;
                    table[row][1] = objectCol;
                    table[row][2] = objectCode;
                    row++;
                }
                else
                {
                    done = TRUE;
                }
            }
        }

        if (ferror(fileRead))
        {
            perror("Error Reading File!");
        }
        fclose(fileRead);
        fileRead = NULL;

        *metaDataTable = table;
    }
}

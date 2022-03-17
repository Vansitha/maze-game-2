#ifndef READMAP_H
#define READMAP_H

#define FALSE 0
#define TRUE !FALSE

void readMetaData(char *filename, int ***metaDataTable, int *metaDataAmount, int *mapRow, int *mapCol);

#endif
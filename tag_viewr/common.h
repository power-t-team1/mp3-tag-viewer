//HAndle the header file iteration
#ifndef COMMON_H
#define COMMON_H

//Include header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tags // Structure to store tagging information. 
{ 
	char title[100], artist[100], album[100], 
		track_num[100], year[100], genre[100]; 
}tat; 
enum status
{
	FAILURE,
	SUCCESS,
	LIST_EMPTY,
	DATA_NOT_FOUND
};

//Declare Prototypes
int edit(char *origin_fil, char *action, char *change);
void merge_file(char* file1, char* file2, char* file3);
#endif

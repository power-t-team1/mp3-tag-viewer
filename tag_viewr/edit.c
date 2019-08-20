#include "common.h"

int edit(char *origin_fil, char *action, char *change)
{
	char * act;
	if(action[0] != '-')
	{
		return FAILURE;
	}
	switch(action[1])
	{
		case 't':
		{
			printf("tit2\n");
			act = "TIT2";
			break;
		}
		default:
		{
			;
		}
	}
	FILE *f1, *f2, *f3;
	char *temp = malloc(sizeof(char) * 30);
	char *buffer;
	char file1[100] = "k.txt", file2[100], file3[100] = "k.mp3";
	f1 = fopen(file1, "ab");
	f2 = fopen(origin_fil, "rb");
	char *length;
	int size;
	unsigned char pad1[7] = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76 }; 
	unsigned char pad2[3] = { 0x00, 0x00, 0x00 }; 
	printf("sksksks\n");
	fprintf(f1, "ID3"); 
	fwrite(pad1, sizeof(pad1), 1, f1);
	fseek(f2,10,SEEK_SET);//went to 10th
	
	while(1)
	{
		printf("enter\n");
		fread(buffer, 1, 4, f2);
		fseek(f2,-4,SEEK_CUR);//go 4 bytes back from cur pos
		if(strcmp(buffer, act) == 0)
		{
			printf("match\n");
			//fseek(f2,-4,SEEK_CUR);//go 4 bytes back from cur pos
			printf("\nEnter the track number of the mp3.\n"); 
			scanf("%[^\n]s", temp);

			fprintf(f1, "%s", act); 

			// Essential 3 NULL bits required for seperation. 
			fwrite(pad2, sizeof(pad2), 1, f1); 

			size = strlen(temp); 
			size++; // Calculating size. 

			// Appending the size of the track number to tag. 
			fprintf(f1, "%c", size); 

			// Essential 3 NULL bits required for seperation. 
			fwrite(pad2, sizeof(pad2), 1, f1); 

			// Adding tag number entered by the user. 
			fprintf(f1, "%s", temp); 

			fseek(f2, size + 10, SEEK_CUR);

		}
		else
		{
			printf("else\n");
			fwrite(f1, 1, 7, f2);
			fscanf(f2, "%hhd", length);
			//fread(length, 1, 1, f2);
			fseek(f2, -1, SEEK_CUR);
				printf("kkkk\n");
			fwrite(f1, 1, 10, f2);//atoi(length) + 3, f2);
			//fwrite(pad2, sizeof(pad2), 1, f1);
		}
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
return SUCCESS;
}
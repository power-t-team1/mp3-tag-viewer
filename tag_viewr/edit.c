#include "common.h"

int edit(char *origin_fil, char *action, char *change)
{
	char * act = malloc(sizeof(char) * 10);
	if(action[0] != '-')
	{
		return FAILURE;
	}
	switch(action[1])
	{
		case 't':
		{
			strcpy(act,"TIT2");
			//printf("ll%s\n", act);
			//act = "TIT2";
			break;
		}
		default:
		{
			printf("Enter a valid action\n");
			exit(0);

		}
	}
	FILE *f1, *f2, *f3;

	char *temp = malloc(sizeof(char) * 30);
	char *buffer = malloc(sizeof(char) * 30);
	char file1[100] = "k.mp3", file2[100], file3[100] = "k.mp3";

	f1 = fopen(file1, "wb");
	f2 = fopen(origin_fil, "rb");

	char length;
	char lam;// = malloc(sizeof(char));;
	int size, ch;
	unsigned char pad1[7] = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
	unsigned char pad2[3] = { 0x00, 0x00, 0x00 }; 

	//printf("sksksks\n");
	printf("hh%s\n", act);

	fprintf(f1, "ID3"); 
	fwrite(pad1, sizeof(pad1), 1, f1);
	fseek(f2,10,SEEK_SET);//went to 10th
	int count = 8;
	while(1)
	{
		printf("\nMajorBEF%ld",ftell(f2));
		printf("enter\n");
		fread(buffer, 1, 4, f2);

		printf("buf:%s\n",buffer );
		printf("act:%s\n",act );
		
		printf("\nbef%ld",ftell(f2));
		fseek(f2, 3, SEEK_CUR);//next three dots
		printf("\naft%ld",ftell(f2));
		//fscanf(f2, "%s", &lam);//get the size from original
		fread(&lam, 1, 1, f2);
		printf("\naft%ld",ftell(f2));
		printf("lam:%c\n",lam);
		printf("lamINT:%d\n",lam);
		//fread(length, 1, 1, f2);
		//fwrite(f1, 1, 10, f2);//atoi(length) + 3, f2);	
	
		fseek(f2,-8,SEEK_CUR);//go 4 bytes back from cur pos
		
		printf("\naft%ld",ftell(f2));
		printf("das\n");
		if(strcmp(buffer, act) == 0)
		{
			printf("bufINS:%s\n",buffer );
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
			//printf("\nINSaft%ld",ftell(f1));
			//fseek(f2, size + 10, SEEK_CUR);
			fseek(f2, lam + 10, SEEK_CUR);
			//printf("\nINSaft1%ld",ftell(f2));
			break;
		}
		else
		{
			//printf("else\n");
			printf("\nf1 else: %ld",ftell(f1));
			printf("\nf2 else: %ld",ftell(f2));
			char *buff1 = malloc(sizeof(char) * 30);
			fread(buff1, 1, 7, f2);
			fwrite(buff1, 1, 7, f1);
			//fseek(f2, 7,SEEK_CUR);

			printf("\naftEls%ld",ftell(f2));
			//fscanf(f2, "%hhd", length);
			fread(&length, 1, 1, f2);
			fseek(f2, -1, SEEK_CUR);
				printf("kkkk\n");
			//fwrite(f1, 1, 10, f2);//atoi(length) + 3, f2);
			printf("len:%c\n",length);
			printf("lenINT:%d\n",length);
			char *buff2 = malloc(sizeof(char) * 30);
			fread(buff2, 1, length + 3, f2);
			fwrite(buff2, 1, length + 3, f1);
			//fseek(f2, length + 3,SEEK_CUR);
			//fwrite(pad2, sizeof(pad2), 1, f1);
		}
		count --;
	}
	while ((ch = fgetc(f2)) != EOF) // Appending tagging info. 
	{
		fputc(ch, f1); 
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
return SUCCESS;
}
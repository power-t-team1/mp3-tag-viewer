#include "common.h"

int edit(char **argv)
{
	char * act = malloc(sizeof(char) * 10);
	char * name = malloc(sizeof(char) * 10);
	
	switch(*((*(argv+3))+1))
	{
		case 't':
		{
			strcpy(act,"TIT2");
			strcpy(name,"title");
			break;
		}
		case 'T':
		{
			strcpy(act, "TRCK");
			strcpy(name,"track");
			break;
		}
		case 'a':
		{
			strcpy(act, "TPE1");
			strcpy(name,"artist");
			break;
		}
		case 'A':
		{
			strcpy(act, "TALB");
			strcpy(name,"Album");
			break;
		}
		case 'c':
		{
			strcpy(act, "TCON");
			strcpy(name,"comment");
			break;
		}
		case 'y':
		{
			strcpy(act, "TYER");
			strcpy(name,"year");
			break;
		}
		default:
		{
			printf("Enter a valid action\n");
			exit(0);

		}
	}
	
	FILE *f1, *f2;
	char *buffer = malloc(sizeof(char) * 3);
	char *temp_buffer = malloc(sizeof(char) * 30);
	char *changesize30 = calloc(sizeof(char) , 29);
	char *changesize4 = calloc(sizeof(char), 3);
	char length;
	unsigned char pad1[7] = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 
	unsigned char pad2[3] = { 0x00, 0x00, 0x00 }; 
	int count = 6, size, ch;

	f1 = fopen("temp.mp3", "wb");
	f2 = fopen(argv[2], "rb");
	fprintf(f1, "ID3"); 
	fwrite(pad1, sizeof(pad1), 1, f1);
	fseek(f2,10,SEEK_SET);//went to 10th
	
	while(count)
	{
		fread(buffer, 1, 4, f2);
		fseek(f2, 3, SEEK_CUR);
		fread(&length, 1, 1, f2);
		fseek(f2,-8,SEEK_CUR);
		
		if(strncmp(buffer, act,4) == 0)
		{
			fprintf(f1, "%s", act); 

			// Essential 3 NULL bits required for seperation. 
			fwrite(pad2, sizeof(pad2), 1, f1); 

			size = strlen(*(argv + 4)); 
			size++; // Calculating size.

			// Appending the size of the track number to tag. 
			fprintf(f1, "%c", size); 

			// Essential 3 NULL bits required for seperation. 
			fwrite(pad2, sizeof(pad2), 1, f1); 

			// Adding tag number entered by the user. 
			fprintf(f1, "%s", *(argv + 4));

			if((strncmp(buffer, "TYER",4) == 0))
			{
				strcpy(changesize4, *(argv+4));
			}
			else
			{
				strcpy(changesize30, *(argv+4));
			}
			fseek(f2, length + 10, SEEK_CUR);
			break;
		}
		else
		{
			fread(temp_buffer, 1, 7, f2);
			fwrite(temp_buffer, 1, 7, f1);
			fread(&length, 1, 1, f2);
			fseek(f2, -1, SEEK_CUR);
			fread(temp_buffer, 1, length + 3, f2);
			fwrite(temp_buffer, 1, length + 3, f1);
		}

		count--;
	}

	while ((ch = fgetc(f2)) != EOF) // Appending tagging info. 
	{
		fputc(ch, f1); 
	}

	switch(*((*(argv + 3))+1))
	{
		case 't'://TIT2
		{
			fseek(f1, -125, SEEK_END);
			fwrite(changesize30,30,1,f1);
			break;
		}
		case 'a'://TPE1
		{
			fseek(f1, -95, SEEK_END);
			fwrite(changesize30,30,1,f1);
			break;
		}
		case 'A'://TALB
		{
			fseek(f1, -65, SEEK_END);
			fwrite(changesize30,30,1,f1);
			break;
		}
		case 'y'://TYER
		{
			fseek(f1, -35, SEEK_END);
			fwrite(changesize4,4,1,f1);
			break;
		}
		case 'c'://COMM
		{
			fseek(f1, -31, SEEK_END);
			fwrite(changesize30,30,1,f1);
			break;
		}
		default:
		{
			printf("enter valid\n");
		}
	}
	fclose(f1);
	fclose(f2);

	FILE *fz, *fd;

	fz = fopen("temp.mp3", "rb");
	fd = fopen(argv[2], "wb");

	while((ch = fgetc(fz)) != EOF)
	{
		fputc(ch, fd);
	}

	remove("temp.mp3");

	fclose(fz);
	fclose(fd);

return SUCCESS;
}

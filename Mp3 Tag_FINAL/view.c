#include "common.h"

int view(char**argv)
{
	//Declare a variable
	FILE *fs;
	char buffer[10] = "\0";
	char size;
	char *str;
	int count = -1, i = 0;

	char  tagname[][20] = {"Song name :","Song name :", "Artist    :", "Ablum     :", "Year      :", "Content   :", "Track     :", "Composer  :", "Copyrigth :", "Language  :", "User define info :", "Time      :", "Date      :", "Lyricist  :", "Info      :" }; 
	char  tag[][6] = {"TIT2", "TPE2", "TPE1", "TALB", "TYER", "TCON", "TRCK", "TCOM", "TCOP", "TLAN", "TXXX", "TIME", "TDAT", "TEXT", "MLLT"}; 

	fs = fopen(*(argv + 2), "rb");

	if (fs == NULL)
	{
		perror(argv[2]);
		return ERROR;
	}

	fseek(fs, 10, SEEK_SET);
	fread(buffer, 1, 4, fs);

	if (!(strcmp(&tag[0][0], buffer)))
	{
		while (++count != 20)
		{   
			fseek(fs, 3, SEEK_CUR);
			fread(&size,1,1,fs);
			fseek(fs, 3, SEEK_CUR);

			for (i = 0;i < 15; i++)
			{
				if (!(strcmp(&tag[i][0], buffer)))
				{
					str = malloc(size * sizeof(char));
					fread(str, 1, size - 1, fs);
					printf("%s", tagname[i]);
					printf("%s\n", str);

					if (size > 30)
					{
						str[30] = '\0';
					}
					break;
				}
			}
			if (i == 15)
			{
				fseek(fs, size - 1, SEEK_CUR);
			}
			fread(buffer, 1, 4, fs);
		}
	}
	else if (!(strcmp(&tag[1][0], buffer)))
	{
		while (++count != 20)
		{
			fseek(fs, 3, SEEK_CUR);
			fread(&size,1,1,fs);
			fseek(fs, 5, SEEK_CUR);

			for (i = 0; i < 15; i++)
			{
				if (!(strcmp(&tag[i][0], buffer)))
				{
					str = malloc(size * sizeof(char));

					for (int j = 0; j < ((size / 2) - 1); j++)
					{
						fread((str+j), 1, 1, fs);
						fseek(fs, 1, SEEK_CUR);
					}

					printf("%s", tagname[i]);
					printf("%s\n", str);

					if (size > 30)
					{
						str[30] = '\0';
					}
					break;
				}
			}

			if (i == 15)
			{
				fseek(fs, size - 3, SEEK_CUR);
			}
			fread(buffer, 1, 4, fs);
		}
	}

	return SUCCESS;
}

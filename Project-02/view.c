#include "common.h"
int view(FILE *fs, char arr[][6])
{
	char buffer[10] = "\0";
	char dat;
	char *str;
	char buff[31];
	int stat;
	int i = 0, count = 0, choice, flag = 0;

	fseek(fs, 10, SEEK_SET);
	while (count != 10)
	{
		fread(buffer, 1, 4, fs);
		count++;
		fseek(fs, 3, SEEK_CUR);
		fread(&dat,1,1,fs);
		for (i = 0; i < 6; i++)
		{
			char *temp = &arr[i][0];
			if (!(strcmp(temp, buffer)))
			{
				flag = 1;
				fseek(fs, 3, SEEK_CUR);
				str = malloc(dat * sizeof(char));
				fread(str,1,dat - 1,fs);
				switch (i)
				{

					case 0 :printf("Song name\t: ");
							if (dat > 30)
							{
								str[30] = '\0';
							}
							printf("%s\n", str);
							break;
					case 1 :printf("Artist\t: ");
							if (dat > 30)
							{
								str[30] = '\0';
							}
							printf("%s\n", str);
							break;
					case 2 :printf("Album\t: ");
							if (dat > 30)
							{
								str[30] = '\0';
							}
							printf("%s\n", str);
							break;
					case 3 :printf("Year\t: ");
							printf("%s\n", str);
							break;
					case 4 :printf("Artist\t: ");
							printf("%s\n", str);
							break;
					case 5 :printf("Comments\t: ");
							printf("%s\n", str);
							if (dat > 30)
							{
								str[30] = '\0';
							}
							break;
				}
				//printf("%s\n", str);
				break;
			}
		}
		if (flag)
		{
			flag = 0;
			continue;
		}
		fseek(fs, dat + 2, SEEK_CUR);
	}
}

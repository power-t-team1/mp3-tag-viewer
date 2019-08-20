#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fs;
	char buffer[10] = "\0";
	char dat;
	char *str;
	int i = 0, count = 0, choice, flag = 0;
	char arr[5][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON"};
	//	char *arr[5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON"};
	fs = fopen("sample.mp3", "r");

	if (fs == NULL)
	{
		return -1;
	}

	fseek(fs, 10, SEEK_SET);

	//	while (count < 6)

	//	{

	//	printf("%s\n", buffer);

	//	while (arr[i][0])
	while (1)
	{
		fread(buffer, 1, 4, fs);
		fseek(fs, 3, SEEK_CUR);
		fread(&dat,1,1,fs);
		//printf("%d\n", dat);
		for (i = 0; i < 5; i++)
		{
			flag = 1;
			char *temp = &arr[i][0];
		//	printf("%s\n", temp);
			if (!(strcmp(temp, buffer)))
			{
		//		printf("%s\n", temp);
				fseek(fs, 3, SEEK_CUR);
				str = malloc(dat * sizeof(char));
				fread(str,1,dat - 1,fs);
				switch (i)
				{
					case 0 :printf("Song name : ");
							break;
					case 1 :printf("Artist : ");
							break;
					case 2 :printf("Albun : ");
							break;
					case 3 :printf("Year : ");
							break;
					case 4 :printf("Artist : ");
							break;
				}
				printf("%s\n", str);
				count++;
				break;
			}
		}
		if (count == 5)
		{
			break;
		}
		if (flag)
		{
			flag = 0;
			continue;
		}
		fseek(fs, dat - 5, SEEK_CUR);
	}
}

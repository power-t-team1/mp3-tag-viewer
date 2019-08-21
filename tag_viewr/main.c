#include "common.h"

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("ERROR : ./mp3_tag_reader : Invalid Arguments\n");
		printf("usage: ./mp3_tag_reader -h for Help\n");
		exit(0);
	}
	FILE *f1;
	char *file1;
	char *tags[] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "TRCK" } ;// malloc(sizeof(char) * 10);
	int status;
	switch(argv[1][1])
	{
		case 'e':
		{
			if(argv[2] == NULL)
			{
				printf("enter the filename\n");
				exit(1);
			}

			status = edit(argv[2], argv[3], argv[4]);
			//printf("dwfwe\n");
			if(status == FAILURE)
			{
				printf("failed\n");
			}
			else
			{
				printf("Tag Editing successful\n");
			}
			break;
		}
		case 'v':
		{
			printf("dfasf\n");
			//print(argv[2], tags);
			break;
		}
		case 'h':
		{
			printf("Help Menu for mp3 Tag Reader and Editor\n\n");
			printf("For viewing the tags- ./mp3_tag_reader -v <.mp3 file_name>\n");
			printf("For editing the tags- ./mp3_tag_reader -e <.mp3 file_name> <modifier> <tags>\n");
			printf("\nModifier\tFunction\n");
			printf("-t\tmodifier Title tag\n-T\tmodifier Track tag\n-a\tmodifier Artist tag\n-A\tmodifier Album tag\n");
			printf("-y\tmodifier year tag\n-c\tmodifier comment tag\n-g\tmodifier Gener tag\n");
			break;
		}
		default:
		{
			printf("Enter the correct format\n");
		}
	}
	return 0;
}
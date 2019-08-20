#include "common.h"

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("enter valids\n");
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
			if(status == FAILURE)
			{
				printf("failed\n");
			}
			break;
		}
		case 'v':
		{
			printf("dfasf\n");
			//print(argv[2], tags);
			break;
		}
		default:
		{
			printf("Enter the correct format\n");
		}
	}
	return 0;
}
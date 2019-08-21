#include "common.h"

int main(int argc, char *argv[])
{
	//Declare variables
	int status;
	//Validating the inputs by calling validate_input function
	status = validate_inputs(argc, argv);
	if (status == ERROR)
	{
		return 0;
	}

	FILE *f1;
	char *file1;
	char arr[6][6] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "TRCK" } ;// malloc(sizeof(char) * 10);
	//Open the file
	f1 = fopen(argv[2], "rb");
	if (f1 == NULL)
	{
		perror(argv[2]);
		return 0;
	}
	switch(argv[1][1])
	{
		case 'e':
			//	status = edit(argv[2], argv[3], argv[4]);
			if(status == FAILURE)
			{
				printf("failed\n");
			}
			else
			{
				printf("Tag Editing successful\n");
			}
			break;
		case 'v':
			//Print the details of the file
			view(f1, arr);
			break;
		default:
			{
				printf("Enter the correct format\n");
			}
	}
	return 0;
}

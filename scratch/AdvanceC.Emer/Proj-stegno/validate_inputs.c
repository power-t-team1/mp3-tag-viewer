#include "common.h"

int validate_inputs(char **argV)
{	
	//check for no. of args
	size_t no_of_arg = 0, i;
	for(i = 0;argV[i] != NULL;i++)
	{
		no_of_arg++;
	}
	if(no_of_arg < 4 || no_of_arg > 5)
	{
		printf("Insufficient arguments\n");
		printf("Usages:\n");
		printf("./steganography -e/-d source.bmp secret.txt destination.bmp\n");
		return ERROR;
	}
	//check for option
	if((strncmp(argV[1],"-e",2) != 0) && (strncmp(argV[1],"-d", 2) != 0))
	{
		printf("Enter correct option i.e -e or -d\n");
		return ERROR;
	}
	//check for correct source file name extension
	size_t len = strlen(argV[2]);
	if(strcmp((argV[2] + (len - 3)),"bmp") != 0)
	{
		printf("Use only files with .bmp extension\n");
		return ERROR;
	}
	//check for correct source file code
	//first we are opening the file
	FILE *fp;
	if((fp = fopen(argV[2], "rb")) == NULL)
	{
		perror("fopen");
		return ERROR;
	}
	unsigned short code;
	fread(&code, 2, 1, fp);
//	printf("%X\n",code);
	if(code != 0x4D42)
	{
		printf("1Use only files with .bmp extension code\n");
		fclose(fp);
		return ERROR;
	}
	fclose(fp);
	//check for correct destination file code
	//first we are opening the file
	/*FILE *fd;
	if((fd = fopen(argV[4], "rb")) == NULL)
	{
		perror("fopen");
		return ERROR;
	}
	unsigned short code1;
	fread(&code1, 2, 1, fd);
	if(code1 != 0x4D42)
	{
		printf("Use only files with .bmp extension code\n");
		fclose(fd);
		return ERROR;
	}
	fclose(fd);*/
	//check for correct secret file code
	//first we are opening the file
	size_t len1 = strlen(argV[3]);
	if(strcmp((argV[3] + (len1 - 3)), "txt") != 0)
	{
		printf("Use secret files only with .txt extension\n");
		return ERROR;
	}
}
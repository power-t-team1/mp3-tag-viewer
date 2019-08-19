#include "common.h"



int copy_head(char **argV)
{
	FILE *fs1, *fs2, *fd;
	fs1 = fopen(argV[2], "rb");
	fd = fopen(argV[4], "rb");

	char buffer[80] = {'\0'};
	//logic for copying from src to dest.
	while(fread(&buffer,1,54,fs1) > 0)
	{
		fwrite(&buffer,1,54,fd);
	}
	//while(fread(&buffer,1,1,fs2) > 0)
	{
	//	fwrite(&buffer,1,1,fd);
	}
	return 0;
}

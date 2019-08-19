#include "common.h"

int encry(char **argV)
{
	//declare vars
	int status, status1, status2, status3, status4, status5;
	//declare the file pointers
	FILE *fs1, *fs2, *fd;
	//open the file in different modes
	fs1 = fopen(argV[2], "rb");
	fs2 = fopen(argV[3], "rb");
	fd = fopen(argV[4], "wb");
	//call the copying the head function
	status = copy_head(fs1, fd);
	//check for the successful execution
	if(status == ERROR)
	{
		printf("Head is not being copied");
		return 0;
	}
	else
	{
		printf("Head copying successful\n");
	}
	//call the passcode encoding function
	status1 = passcode(fs1, fd);
	//check for its successful execution
	if(status1 == ERROR)
	{
		printf("Passcode encoding Unsuccessful\n");
		return 0;
	}
	else
	{
		printf("Passcode has been encoded successfully\n");
	}
	//call the length function
	status2 = length(fs1, fs2, fd);
	//check for its successful execution
	if(status2 == ERROR)
	{
		printf("Length encoding Unsuccessful\n");
		return 0;
	}
	else
	{
		printf("Length copying Successful\n");
	}
	//use rewind to point the file pointer to the start of the secret message
	rewind(fs2);
	//call the encoding function
	status3 = encode(fs1, fs2, fd);
	//check for its successful execution
	if(status3 == ERROR)
	{
		printf("Encoding Unsuccessful\n");
		return 0;
	}
	else
	{
		printf("Encoding Successful\n");
	}
	//call the copy tail function to copy the rest of the file.
	status4 = copy_tail(fs1, fd);
	//check for its successful execution
	if(status4 == ERROR)
	{
		printf("Copying rest of the data Unsuccessful\n");
		return 0; 
	}
	else
	{
		printf("Copying rest of the data successful\n");
	}
}
//define the head copying function to copy upto 54bytes
int copy_head(FILE *fs1, FILE *fd)
{
	//declare loacl vars
	int x,y; 
	char buffer[80] = {'\0'};
	//logic for copying from src to dest.
	x = fread(&buffer,1,54,fs1);
	y = fwrite(&buffer,1,54,fd);
	//check for error
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
		
	}
}
//define the passcode encoding function.
int passcode(FILE *fs1, FILE *fd)
{
	//declare the local vars
	int x , y;
	unsigned pass, temp;
	//prompt + read the user password
	printf("Enter the password:\n");
	scanf("%u", &pass);
	char buffer, buff;
	unsigned char num;
	unsigned mask, bit;
	//encode the passcode
	mask = 1;
	mask = mask << 31;//using MSB
	for( ;mask;mask = mask >> 1)
	{
		x = fread(&buff,1,1,fs1);// read the source file
		if(pass & mask)
		{
			buffer = buff | 0x01; 
			y = fwrite(&buffer,1,1,fd);//write to the dest file
		}
		else
		{
			buffer = buff & ~(0x01); 
			y = fwrite(&buffer,1,1,fd);	//write to the dest file
		}	
	}
	//check if the files are read and wriiten correctly.
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
		
	}
}
//define the length function to get the length of the secret message
int length(FILE *fs1, FILE *fs2, FILE *fd)
{
	//define the local vars
	int x, y;
	char buff, buffer;
	int count;
	int length;
	unsigned char num;
	unsigned mask, bit;

	mask = 1;
	mask = mask << 31;
	//get the length of the message
	fseek(fs2,0,SEEK_END);
	unsigned long int size = ftell(fs2);
	rewind(fs2);
	//print the size of the secret message
	printf("Size is : %lu\n", size);
	//encode the secret message length to the bmp file
	for( ;mask;mask = mask >> 1)
	{
		x = fread(&buff,1,1,fs1);
		if(size & mask)
		{
			buffer = buff | 0x01; 
			y = fwrite(&buffer,1,1,fd);
		}
		else
		{
			buffer = buff & ~(0x01); 
			y = fwrite(&buffer,1,1,fd);	
		}	
	}	
	//printf("%ld\n", ftell(fs1) );
	//check for error
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
		
	}
}
//define the encoding function
int encode(FILE *fs1, FILE *fs2, FILE *fd)
{
	//declare local vars
	int x, y;
	//point the secret msg file pointer to the start of the file
	rewind(fs2);
	//printf("%ld\n", ftell(fs1) );
	char ch1, buff, buffer;
	size_t count,length;
	unsigned char num;
	unsigned mask;
	
	//read and encode the secret msg
	//printf("%ld\n", ftell(fs1) );
	while(fread(&ch1,1,1,fs2) > 0)
	{
		mask = 1;
		mask = mask << 7;
		for( ;mask;mask = mask >> 1)
		{
			x = fread(&buff,1,1,fs1);
			if(ch1 & mask)
			{
				buffer = buff | 0x01; 
				y = fwrite(&buffer,1,1,fd);
			}
			else
			{
				buffer = buff & ~(0x01); 
				y = fwrite(&buffer,1,1,fd);	
			}	
		}
	}
	//printf("%ld\n", ftell(fs1));
	//check for errors
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
		
	}
}
//define the tail copying function to copy the remaining data to complete the deastion file to looks sane as the source file
int copy_tail(FILE *fs1, FILE *fd)
{
	//declare vars
	int x, y;
	char buffer;
	//logic to read and copy data to the destination file
	while((x = fread(&buffer,1,1,fs1)) > 0)
	{
		y = fwrite(&buffer,1,1,fd);
	}
	//check for error
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
		
	}
}
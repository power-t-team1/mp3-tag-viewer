#include "common.h"

int decry(char **argV)
{
	//declare the vars
	int status, status1, status2;
	unsigned len;
	//declare file pointers
	FILE *fs1, *fs2, *fd;
	//open the files in respective modes
	fs1 = fopen(argV[2], "rb");
	fd = fopen(argV[3], "wb");
	//call the read passcode function
	status = read_passcode(fs1);
	if(status == ERROR)//check for error in passcode reading
	{
		printf("reading the password unsuccessful\n");
		return 0;
	}
	else
	{
		printf("Reading the passcode successful\n");
	}
	//call the length funstion
	len = get_len(fs1);
	//call the decrption function
	status2 = decrypt(fs1, fd, len);
	if(status2 == ERROR)//check for error in decryption
	{
		printf("Decryption unsuccessful\n");
		return 0;;
	}
	else
	{
		printf("Decryption successful\n");
	}
		
}
//define the passcode reading function
int read_passcode(FILE *fs1)
{
	//declare the local vars
	int x;
	//go to the 54the loctation from the start of the encoded file.
	fseek(fs1,54,SEEK_SET);
	unsigned pass = 0, temp;
	char buffer, buff;
	unsigned char num;
	unsigned mask, bit;
	int hidden;
	int i = 0;
	//read the passcode
	for( ;i < 32;)
	{
		x = fread(&buff,1,1,fs1);
		int temp = buff;
		int mask = 1;
		if(temp & mask)
		{
			pass = pass | (1 << (31 - i)); 
		}
		i++;	
	}
	//prompt + read user passcode
	printf("Enter the passcode:\n");
	scanf("%d", &hidden);
	if(hidden != pass)
	{
		printf("Incorrect passcode!\n");
		exit(1);
	}
	//check for successful execution
	if(x == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
	}
}
//define the length function
int get_len(FILE *fs1)
{
	//declare the local vars
	unsigned len = 0, temp;
	char buffer, buff;
	unsigned char num;
	unsigned mask, bit;
	int i = 0;

	for( ;i < 32;)
	{
		fread(&buff,1,1,fs1);
		int temp = buff;
		int mask = 1;
		if(temp & mask)
		{
			len = len | (1 << (31 - i)); 
		}
		i++;	
	}
	return len;
	printf("length is :%u\n", len);
}
//declare the decryption function
int decrypt(FILE *fs1, FILE *fd, unsigned len)
{
	//declare local variable
	char buff;
	int x, y;
	int i, j;
	//decode passcode
	for(i = 0;i < (int)len;i++)
	{
		char data = 0;
		for(j = 0;j < 8;j++)
		{
			x = fread(&buff,1,1,fs1);
			if(buff & 0x01)
			{ 
				data = data | (0x01 << (7 - j)); 
			}
		}	
		y = fwrite(&data,1,1,fd);	
	}
	//printf("%u\n", data);
	//printf("%lu\n", ftell(fs1));	
	//check for successful execution of the function
	if(x == 0 && y == 0)
	{
		return ERROR;
	}
	else
	{
		return SUCCESS;
	}
}



/*
int decrypt(FILE *fs1, FILE *fd, int len)
 {
      int i, j;
      char f;
      for(i = 1; i <= len; i++)
      {
         char text = 0;
         int k = 7;
         for(j = 1; j <= 8; j++)
         {
             fread(&f, 1, 1, fs1);
             if (f & 0x01)
                 text = text |  0x01 << k;
              k--;
         }
         fwrite(&text, 1, 1, fd);
      }
 }
*/
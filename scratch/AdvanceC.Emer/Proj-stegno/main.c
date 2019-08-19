#include"common.h"

int main(int argC, char * argV[])
{
	//clear the screen
	system("clear");
	//declare the vars
	int status, status1, status2;
	//call the validation function to check for the errors.
	status = validate_inputs(argV);
	// check if the function has executed successfully
	if(status == -1)
	{
		return 0;
	}
	//check for the correct option
	if((strncmp(argV[1],"-e",2) == 0))	
	{
		status1 = encry(argV);
		//check if the encryption has happened successfully
		if(status1 == 0)
		{	
			return 0;
		}
	}
	else
	{
		status2 = decry(argV);
		//check if the decrption has happened succesfully
		if (status2 == 0)
		{
			return 0;
		}
	}
	return 0;
}

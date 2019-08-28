#include "common.h"

int main(int argc, char*argv[])
{
	//Declare a variable
	int status;

	//Calling function for validation
	status = validate_inputs(argv);


	if (status == SUCCESS)
	{
		if ((strncmp(*(argv + 1),"-v", 2)) == 0)
		{
			status = view(argv);

			if (status == SUCCESS)
			{
				printf("View SUCCESS\n");
			}
			else
			{
				printf("View ERROR\n");
			}
		}
		else if ((strncmp(*(argv + 1),"-e", 2)) == 0)
		{
			status = edit(argv);

			if (status == SUCCESS)
			{
				printf("EDIT SUCCESS\n");
			}
			else
			{
				printf("Edit ERROR\n");
			}
		}
	}
	else if(status == ERROR)
	{
		printf("Validation ERROR\n");
	}
}

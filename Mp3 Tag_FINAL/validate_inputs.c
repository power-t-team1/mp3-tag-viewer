//include user header files
#include "common.h"

//Function definition for validate a inputs
int validate_inputs(char**argv)
{
	//Declare a variable
	size_t i, no_of_args = 0;
	static const char Modifier[][3] = {"-T", "-t", "-a", "-A", "-y", "-c", "-g"};

	//Count the argument in the command line argument
	for (i = 0; *(argv + i); i++ )
	{
		no_of_args++;
	}
	
	//Error handling for how files user enter in command line argument
	if (no_of_args == 1)
	{
		//Promot the user
		printf("For viewing the files : ./mp3_tag_reader <-v> <.mp3 file> \n" );
		printf("For editing the files : ./mp3_tag_reader <-e> <.mp3 file> <modifier> <tag> \n");
		printf("./mp3_tag_reader <Option[1]> <Option[2]> <Option[3]>  Option[4]\n");
		printf("Option[1] = View <-v> or Edit <-e> or Help <-h>\n");
		printf("Option[2] = Source file format (.mp3)\n");
		printf("Option[3] = Modifier ( \n -t => Title tag\n -T => Track tag\n -a => Artist tag\n -A => Album tag\n -y => Year tag\n -c => Comment tag\n -g => Genre)\n");
		printf("Option[4] = <tagname>\n");
		
		//Return error
		return ERROR;
	}

	//Error handling for option[1] view
	if ((strncmp(*(argv+1), "-v", 2) == 0))
	{
		//Error handling for how files user enter in command line argument
		if (no_of_args < 3)
		{
			//Promot the user
			printf("Insufficient Argument\n");
			printf("Usage :\n");
			printf("./mp3_tag_reader <Option[1]> <Option[2]>\n");
			printf("Option[1] = View <-v>\n");
			printf("Option[2] = Source file format (.mp3)\n");
			//Return error
			return ERROR;
		}

		//Error handling for check file format is mp3 or not
		if (format_mp3(*(argv + 2)) != 0)
		{
			//Promot the user
			printf("Invalid file format\n");
			printf("Option[2] = Source file format(.mp3)\n");

			//Return error
			return ERROR;
		}

		
		//Error handling for check file version is IDV or not
		if (internal_version_mp3(*(argv + 2)) != 0)
		{
			//promot the user
			printf("Invalid file version \n");
			printf("option[2] = Source file version (ID)");

			//Result error
			return ERROR;
		}
		
		//Return no  error
		return SUCCESS;
	}
	else if ((strncmp(*(argv+1), "-e", 2) == 0))
	{
		if (no_of_args < 4)
		{
			//Promot the user
			printf("Insufficient Argument\n");
			printf("Usage :\n");
			printf("./mp3_tag_reader <Option[1]> <Option[2]> <Option[3]>  Option[4]\n");
			printf("Option[1] = Edit <-e>\n");
			printf("Option[2] = Source file format (.mp3)\n");
			printf("Option[3] = Modifier ( \n -t => Title tag\n -T => Track tag\n -a => Artist tag\n -A => Album tag\n -y => Year tag\n -c => Comment tag\n -g => Genre)\n");
		    printf("Option[4] = <tagname>\n");

			//Return error
			return ERROR;
		}

		//Error handling for check file format is mp3 or not
		if (format_mp3(*(argv + 2)) != 0)
		{
			//Promot the user
			printf("Invalid file format\n");
			printf("Option[2] = Source file format (.mp3)\n");

			//Return error
			return ERROR;
		}

		//Error handling for check file version is IDV or not
		if (internal_version_mp3(*(argv + 2)) != 0)
		{
			//promot the user
			printf("Invalid file version \n");
			printf("option[2] = Source file version (IDV)");

			//Result error
			return ERROR;
		}

		
		//Error handling for modifier
		i = 0;
		while (i != 8)
		{
			if ((strncmp(*(argv + 3),Modifier[i++], 2) == 0))
			{
				break;
			}
			else if (i > 6) 
			{	
				//Promot the user
				printf("Invalid \n");
				printf("Option[3] = Modifier ( \n -t => Title tag\n -T => Track tag\n -a => Artist tag\n -A => Album tag\n -y => Year tag\n -c => Comment tag\n -g => Genre)\n");
				break;
			}
		}

		//Error handling for check file version is IDV or not
		if ((*(argv + 4)) == NULL)
		{
			//promot the user
			printf("Invalid \n");
			printf("Option[4] = <tagname>\n");

			//Result error
			return ERROR;
		}
		

		//Return a no error 
		return SUCCESS;
	}
	else if (!(strcmp(argv[1], "-h")))
	{
		//Promot the user
		printf("For viewing the files : ./mp3_tag_reader <-v> <.mp3 file> \n" );
		printf("For editing the files : ./mp3_tag_reader <-e> <.mp3 file> <modifier> <tag> \n");
		printf("./mp3_tag_reader <Option[1]> <Option[2]> <Option[3]>  Option[4]\n");
		printf("Option[1] = View <-v> or Edit <-e> or Help <-h>\n");
		printf("Option[2] = Source file format (.mp3)\n");
		printf("Option[3] = Modifier ( \n -t => Title tag\n -T => Track tag\n -a => Artist tag\n -A => Album tag\n -y => Year tag\n -c => Comment tag\n -g => Genre)\n");
		printf("Option[4] = <tagname>\n");
		
		//Return help
		return HELP;
	}
	else
	{
		//Promot the user
		printf("Insufficient Argument\n");
		printf("Usage :\n");
		printf("./mp3_tag_reader <Option[1]> <Option[2]> <Option[3]>  Option[4]\n");
		printf("Option[1] = View <-v> or Edit <-e> or Help <-h>\n");
		printf("Option[2] = Source file format (.mp3)\n");
		printf("Option[3] = Modifier ( \n -t => Title tag\n -T => Track tag\n -a => Artist tag\n -A => Album tag\n -y => Year tag\n -c => Comment tag\n -g => Genre)\n");
		printf("Option[4] = <tagname>\n");
		
		//Return error
		return ERROR;
	}

		//Return no  error
		return SUCCESS;
}

//Function definition for format_mp3
int format_mp3(char*argv)
{
	//Declare a varible
	int length;

	//Error handling for option[2] 
	length = strlen(argv);

	//Error handling for check file format is bmp or not
	if (strcmp(argv + (length - 3), "mp3") != 0)
	{
		//Return error
		return ERROR;
	}
}

//Function definition for internal_version_mp3 
int internal_version_mp3(char*argv)
{
        //Declare a varible
        unsigned int code;
        FILE * fp;

        //Error handling for internal file format
        if ((fp = fopen(argv, "rb")) == NULL)
        {
                perror("fopen : argv[2]");

                //Return a error
                return ERROR;
        }

        //Read a 2 bytes form the source file
        fread(&code, 2, 1, fp);

        //Checking a file verision is IDV or not
        if (code != 0X4449)
        {
                //Close a file
                fclose(fp);

                //Return a error
                return ERROR;
        }
        //close a file
        fclose(fp);
}


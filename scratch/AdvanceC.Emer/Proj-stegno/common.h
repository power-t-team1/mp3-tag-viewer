//handle the header file itirate
#ifndef RAM_K
#define RAM_K

//include header files
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
//macro definitions
#define ERROR -1
#define SUCCESS 1

//UDDT

//function prototypes
int validate_inputs(char **argV);
		//encrypt functions
int copy_head(FILE *fs1, FILE *fd);
int passcode(FILE *fs1, FILE *fd);
int encry(char **argV);
int length(FILE *fs1, FILE *fs2, FILE *fd);
int encode(FILE *fs1, FILE *fs2, FILE *fd);
int copy_tail(FILE *fs1, FILE *fd);
		//decrypt functions
int decry(char **argV);
int read_passcode(FILE *fs1);
int get_len(FILE *fs1);
int decrypt(FILE *fs1, FILE *fd, unsigned);

#endif

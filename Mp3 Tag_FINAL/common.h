#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR -1
#define SUCCESS 0
#define HELP 1
int validate_inputs(char**argv);
int format_mp3(char*argv);
int internal_version_mp3(char*argv);
int view(char**argv);
int edit(char**argv);
int print(char**argv);
#endif

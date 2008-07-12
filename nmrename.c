/*
 * main.c
 * This file is part of nmrename
 *
 * Copyright (C) 2007 - Stefan Lohmaier
 *
 * nmrename is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * nmrename is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with nmrename; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */
 
//headers
//---
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "msg.h"
#include "funcs.h"
#include "cmd.h"
#include "nmopt.h"

//globals
//---
unsigned short force=0; //force renaming? no questions asked

//main-Program
//---
int main(int argc, char **argv) {
	//vars
	int argindex=0;
	static struct nmopts options[] = {
		{nmcmdhelp, "-h", 0, NULL},
		{nmcmdforce, "-f", 0, NULL},
		{nmcmddelete, "-d", 2, "Deleting from %s to %s:"},
		{nmcmdstrdelete, "-sd", 1, "Deleting \'%s\'"},
		{nmcmdstrreplace, "-sr", 2, "Replacing \'%s\' with \'%s\'"},
		{nmcmdstrinsert, "-si", 2, "Inserting \'%s\' at %s"},
		{nmcmdstrcasecamel, "-cc", 0, "Camelcasing"},
		{nmcmdstrcaselower, "-cl", 0, "Lowercasing"},
		{nmcmdstrcaseupper, "-cu", 0, "Upppercasing"},
		{nmcmdfielddelete, "-fd", 2, "Deleting field %s delimited by \'%s\'"},
		{nmcmdfieldswitch, "-fs", 3, "Switching field %s with %s delimited by \'%s\'"},
		{nmcmderror, NULL, -1 ,NULL}
	};
	struct nmopts *option;
	char **pathlist=NULL;
	int pathno=0;
	int error=0;

	//Let's first check if everything is ok
	while((option=nmopt(argv, argc, options, &argindex)) != NULL) {
		switch(option->id) {
			//special treatment for help
			case nmcmdhelp: nm_help(); return(0);

			//enough arguemnts for all commands?
			case nmcmdforce:
			case nmcmddelete:
			case nmcmdfielddelete:
			case nmcmdfieldswitch:
			case nmcmdstrcasecamel:
			case nmcmdstrcaselower:
			case nmcmdstrcaseupper:
			case nmcmdstrdelete:
			case nmcmdstrinsert:
			case nmcmdstrreplace:
				//check if enough arguments left
				if(argc-argindex-option->argcount<1) {
					nm_error(0, "%d. argument \'%s\' has not enough arguments!", argindex, argv[argindex]);
					error=1;
				}
				argindex+=option->argcount;
				break;
			
			//It's no command? Is it a file?
			default:
				//Is it a path?
				if(is_path(argv[argindex])!=1) {
					nm_error(0, "%d. argument \'%s\' is neither a file nor a command!", argindex, argv[argindex]);
					error=1;
				}
		}
	}
	//Error encountered? exit.
	if(error==1) return(1);
	
	//Now we can execute everything
	argindex=0;
	while((option=nmopt(argv, argc, options, &argindex)) != NULL) {
		switch(option->id) {
			//switches
			case nmcmdforce: force=1; break;
			
			//Group rename functions
			case nmcmddelete:
			case nmcmdfielddelete:
			case nmcmdfieldswitch:
			case nmcmdstrcasecamel:
			case nmcmdstrcaselower:
			case nmcmdstrcaseupper:
			case nmcmdstrdelete:
			case nmcmdstrinsert:
			case nmcmdstrreplace:
				nmrename(pathlist, pathno, option->id, option->text, argv[argindex+1], argv[argindex+2], argv[argindex+3]);
				argindex+=option->argcount;
				break;
			
			//Add the files
			default:
				nm_msg("Adding \'%s\' to filelist.", argv[argindex]);
				pathlist=(char **) realloc(pathlist, sizeof(char *) * (pathno+1));
				pathlist[pathno++]=argv[argindex];
				break;
		}
	}
	
	//Good bye!
	return(0);
}

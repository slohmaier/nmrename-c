/*
  *main.c
  *This file is part of nmrename
 *
  *Copyright (C) 2007 - Stefan Lohmaier
 *
  *nmrename is free software; you can redistribute it and/or modify
  *it under the terms of the GNU General Public License as published by
  *the Free Software Foundation; either version 2 of the License, or
  *(at your option) any later version.
 *
  *nmrename is distributed in the hope that it will be useful,
  *but WITHOUT ANY WARRANTY; without even the implied warranty of
  *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *GNU General Public License for more details.
 *
  *You should have received a copy of the GNU General Public License
  *along with nmrename; if not, write to the Free Software
  *Foundation, Inc., 51 Franklin St, Fifth Floor, 
  *Boston, MA  02110-1301  USA
 */
 
//headers
//---
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "funcs.h"
#include "cmd.h"

//globals
//---
unsigned short force=0; //force renaming? no questions asked

//main-Program
//---
int main(int argc, char* *argv) {
	//vars
	int arg=1;            //counter for argument parsing. (start at first argument)
	char** pathlist=NULL; //list for paths to rename
	int pathno=0;         //count for paths in pathlist
	
	//parse arguments one by one
	while(arg<argc) {
		//First parse for commands
		//---
		//print help
		if(strcmp("-h", argv[arg]) == 0) {
			nm_help();
		}
		//activate force mode
		else if(strcmp("-f", argv[arg]) == 0) {
			force=1;
		}
		//remove from pos1 to pos2
		else if(strcmp("-d", argv[arg]) == 0) {
			//enough arguments left?
			if(argc-2-arg<1)
				nm_error("Too less arguments left for delete cmd.");
			
			pathlist=nm_delete(pathlist, pathno, argv[arg+1], argv[arg+2]);
			arg+=2;
		}
		//replace str1 with str2
		else if(strcmp("-sr", argv[arg]) == 0) {
			//enough arguments left?
			if(argc-2-arg<1)
				nm_error("Too less arguments left for string replace cmd.");
			
			pathlist=nm_replace_str(pathlist, pathno, argv[arg+1], argv[arg+2]);
			arg+=2;
		}
		//delete str
		else if(strcmp("-sd", argv[arg]) == 0) {
			//enough arguments left?
			if(argc-1-arg<1)
				nm_error("Too less arguments left for string replace cmd.");
			
			pathlist=nm_delete_str(pathlist, pathno, argv[arg+1]);
			arg++;
		}
		//insert str at pos
		else if(strcmp("-si", argv[arg]) == 0) {
			//enough arguments left?
			if(argc-2-arg<1)
				nm_error("Too less arguments left for string insert cmd.");
			
			pathlist=nm_insert_str(pathlist, pathno, argv[arg+1], argv[arg+2]);
			arg+=2;
		}
		//camelcase
		else if(strcmp("-cc", argv[arg]) == 0) {
			pathlist=nm_camel_case_str(pathlist, pathno);
		}
		//uppercase
		else if(strcmp("-cu", argv[arg]) == 0) {
			pathlist=nm_upper_case_str(pathlist, pathno);
		}
		//lowercase
		else if(strcmp("-cl", argv[arg]) == 0) {
			pathlist=nm_lower_case_str(pathlist, pathno);
		}
		//delete field
		else if(strcmp("-df", argv[arg]) == 0) {
			//enough arguments left?
			if(argc-2-arg<1)
				nm_error("Too less arguments left for delete field cmd.");
			
			pathlist=nm_delete_field(pathlist, pathno, argv[arg+1], argv[arg+2]);
			arg+=2;
		}
		//probably a file?
		else if(is_path(argv[arg])==1) {
			nm_msg("Adding \'%s\' to filelist.", argv[arg]);
			pathlist=(char **) realloc(pathlist, sizeof(char *)  *(pathno+1));
			pathlist[pathno++]=argv[arg];
		}
		//neither file nor command
		else
			nm_error("%d. argument \'%s\' is neither a file nor a command!", arg, argv[arg]);
		
		//next arg
		arg++;
	}
	
	//good bye!
	return 0;
}

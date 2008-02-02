/*
  *cmd.c
  *This file is part of nmrename
 *
  *Copyright (C) 2007 - Stefan Lohmaier
 *
  * nmrename is free software; you can redistribute it and/or modify
  *it under the terms of the GNU General Public License as published by
  *the Free Software Foundation; either version 2 of the License, or
  *(at your option) any later version.
 *
  * nmrename is distributed in the hope that it will be useful,
  *but WITHOUT ANY WARRANTY; without even the implied warranty of
  *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *GNU General Public License for more details.
 *
  *You should have received a copy of the GNU General Public License
  *along with  nmrename; if not, write to the Free Software
  *Foundation, Inc., 51 Franklin St, Fifth Floor, 
  *Boston, MA  02110-1301  USA
 */
 
//headers
//---
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "str.h"
#include "funcs.h"

//delete from pos1 to pos2.
//---
char **nm_delete(char* *pathlist, int pathno, char* cpos1, char* cpos2) {
	//vars
	//---
	char **newlist; //new pathlist
	int i;          //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mDeleteting from %s to %s:\033[m", cpos1, cpos2);
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		//delete. on error just copy
		if((newlist[i]=nm_str_delete(pathlist[i], cpos1, cpos2))==NULL) {
			newlist[i]=pathlist[i];
			nm_warn("Omitting \'%s\'. Would delete whole filename", newlist[i]);
		}
		else
			nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//replace str1 with str2
//---
char **nm_replace_str(char **pathlist, int pathno, char *str1, char* str2) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mReplacing %s with %s:\033[m", str1, str2);
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_replace(pathlist[i], str1, str2);
		if(strcmp(newlist[i],pathlist[i])!=0)
			nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//delete str
//---
char **nm_delete_str(char **pathlist, int pathno, char *str) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mDeleting %s:\033[m", str);
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_replace(pathlist[i], str, "");
		
		//if new is empty just copy
		if(*newlist[i]=='\0') {
			free(newlist[i]);
			newlist[i]=pathlist[i];
			nm_warn("Omitting \'%s\'. Would delete whole pathname", newlist[i]);
		}
		else
			if(strcmp(newlist[i],pathlist[i])!=0)
				nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//insert str at cpos
//---
char **nm_insert_str(char **pathlist, int pathno, char *str, char* cpos) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mInserting %s at %s:\033[m", str, cpos);
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_insert(pathlist[i], str, cpos);
		nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//camelcase str
//---
char **nm_camel_case_str(char **pathlist, int pathno) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mCamelcasing :\033[m");
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_case_camel(pathlist[i]);
		nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//lowercase str
//---
char **nm_lower_case_str(char **pathlist, int pathno) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mLowercasing :\033[m");
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_case_lower(pathlist[i]);
		nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//uppercase str
//---
char **nm_upper_case_str(char **pathlist, int pathno) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mUppercasing :\033[m");
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_case_upper(pathlist[i]);
		nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

//delete field cnum from str with delimiters dels
//---
char **nm_delete_field(char **pathlist, int pathno, char *cnum, char *dels) {
	//vars
	//---
	char **newlist;        //new pathlist
	int i;                 //runner
	
	//create new pathlist
	newlist=(char **) malloc(sizeof(char *)  *pathno);
	
	//welcome
	nm_msg("");
	nm_msg("\033[1mDeleting field %s with delimiters %s :\033[m", cnum, dels);
	nm_msg("");
	
	//fill new list
	for(i=0; i<pathno; i++) {
		newlist[i]=nm_str_delete_field(pathlist[i], cnum, dels);
		nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//start renaming?
	nm_rename(pathlist, newlist, pathno);
	
	return(newlist);
}

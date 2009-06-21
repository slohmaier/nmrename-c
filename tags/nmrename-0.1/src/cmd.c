/*
 * cmd.c
 * This file is part of nmrename
 *
 * Copyright (C) 2007 - Stefan Lohmaier
 *
 *  nmrename is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 *  nmrename is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with  nmrename; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */
 
//headers
//---
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "msg.h"
#include "str.h"
#include "funcs.h"
#include "cmd.h"

unsigned short force;

void nmrename(char **pathlist, int pathno, nmcmd cmd, char *cmdtext, char *arg1, char *arg2, char *arg3) {
	char **newlist;
	int i, j;
	char answer;
	//the function pointer
	char *(*renamefunc)(char*, char*, char*, char*) = NULL;
	
	//check if list is empty
	if(pathlist==NULL) nm_error(1, "Pathlist is empty! Nothing to rename!");
	
	//generate new map
	newlist = (char **) malloc(sizeof(char *) * (pathno+1));
	
	//assign the function pointer
	switch(cmd) {
		case nmcmddelete:       renamefunc=nm_str_delete; break;
		case nmcmdfielddelete:  renamefunc=nm_str_delete_field; break;
		case nmcmdfieldswitch:  renamefunc=nm_str_switch_field; break;
		case nmcmdstrcasecamel: renamefunc=nm_str_case_camel; break;
		case nmcmdstrcaselower: renamefunc=nm_str_case_lower; break;
		case nmcmdstrcaseupper: renamefunc=nm_str_case_upper; break;
		case nmcmdstrdelete:    renamefunc=nm_str_delete_str; break;
		case nmcmdstrinsert:    renamefunc=nm_str_insert; break;
		case nmcmdstrreplace:   renamefunc=nm_str_replace; break;
		case nmcmdlist:         renamefunc=nm_str_list; break;
		default:
			nm_error(1, "Well. This shouldn't happen.");
			break;
	}
	
	//the cmdtext is in printf format.
	nm_msg("");
	nm_msg(cmdtext, arg1, arg2, arg3);
	nm_msg("");
	
	//create new list
	for(i=0; i<pathno; i++) {
		//rename the path
		newlist[i]=renamefunc(pathlist[i], arg1, arg2, arg3);
		
		//if renaming failed omitt and just copy
		if(newlist[i]==NULL || strcmp(newlist[i], "") == 0) {
			newlist[i]=pathlist[i];
			nm_msg("Omitting\'%s\'", pathlist[i]);
		}
		//if paths are the same free the memory of the new one and assign old one
		else if(strcmp(newlist[i], pathlist[i]) == 0) {
			free(newlist[i]);
			newlist[i]=pathlist[i];
		}
		else
			nm_msg("\'%s\' --> \'%s\'", pathlist[i], newlist[i]);
	}
	
	//Now to the renaming!
	
	//Only ask if force is not set.
	if(force==0) {
		nm_msg("");
		nm_msg("Start renaming?");
		
		//ask until user gives a valid answer.
		do {
			printf("<< [y/n]:");
			fflush(stdin);
			answer=getchar();
			if(answer!='\n') getchar();
		} while(answer!='y' && answer!='n');
		
		//exit if no
		if(answer=='n')
			return;
	}
	
	nm_msg("");
	nm_msg("Checking for Duplicate paths.");
	
	//check for duplicates
	for(i=0; i<pathno; i++)
		for(j=0; j<pathno; j++) {
			if(j!=i && strcmp(newlist[i], newlist[j])==0)
				nm_error(1, "More than one path would be renamed to '%s'", newlist[i]);
		}
	
	//rename everything
	nm_msg("Starting renaming...");
	nm_msg("");
	for(i=0; i<pathno; i++) {
		nm_msg("Renaming \'%s\' to \'%s\'", pathlist[i], newlist[i]);
		rename(pathlist[i], newlist[i]);
		pathlist[i]=newlist[i];
	}
	nm_msg("");
	nm_msg("Renaming done.");
}

/*
  *funcs.c
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
 
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "msg.h"

//globals
//---
unsigned short force;

//is path a valid one?
//---
unsigned short is_path(char *path) {
	struct stat test;
	if(stat(path, &test)==-1)
		return(0);
	else
		return(1);
}

//create real positions from char pos
//---
int nm_convert_pos(char *str, char* cpos) {
	//vars
	//---
	int pos; //resulting position
	char *p; //result pointer for strtol
	
	//do the actual conversion
	pos=strtol(cpos, &p, 10);
	
	//error during conversion?
	if(*p!='\0')
		return -1;
	
	//position from right?
	if(cpos[0]=='-') 
		pos=strlen(str)-1+pos;
	
	//polish position (not smaller than 0. not bigger then size of str
	if(pos<0)
		pos=0;
	if(pos>strlen(str)-1)
		pos=strlen(str)-1;
	
	return pos;
}

//rename paths from old to new
//---
void nm_rename(char **old, char **new, int pathno) {
	//vars
	//---
	char answer; //answer from question
	int i,j;     //runner
	
	if(force==0) {
		nm_msg("");
		nm_msg("Start renaming?");
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
	
	//check for duplicates
	nm_msg("");
	nm_msg("Checking for Duplicate paths.");
	for(i=0; i<pathno; i++)
		for(j=0; j<pathno; j++) {
			if(j!=i && strcmp(new[i], new[j])==0)
				nm_error("More than one path would be renamed to '%s'", new[i]);
		}
	
	//rename everything
	nm_msg("Starting renaming...");
	for(i=0; i<pathno; i++) {
		rename(old[i], new[i]);
		
		//if new!=old path free, because no longer needed
		if(new[i]!=old[i])
			free(new[i]);
	}
	nm_msg("Renaming done.");
}

// is c a whitespace?
//---
short nm_check_ws(char c) {
	switch (c) {
		case ' ':
		case '\t':
		case '\n':
		case '-':
			return(1);
		
		default:
			return(0);
	}
}

// is c part of string?
//---
short nm_check_partof(char c, char *string) {
	char *i;
	for(i=string; *i!='\0'; i++)
		if(*i==c)
			return(1);
	return(0);
}

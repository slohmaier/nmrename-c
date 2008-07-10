/*
 * funcs.c
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
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"
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

//create numeric positions from string positions
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
	
	//polish position (not smaller than 0. not bigger then size of str)
	if(pos<0)
		pos=0;
	if(pos>strlen(str)-1)
		pos=strlen(str)-1;
	
	return pos;
}

// is c a whitespace?
//---
short nm_check_ws(char c) {
	switch (c) {
		//whitespace list
		case ' ':
		case '\t':
		case '\n':
		case '-':
			return(1);
		
		//not a whitespace
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

//convert field to start and end pointers off the field
struct nmfield *nm_convert_field(char *str, char *cfield, char *dels) {
	//vars
	//---
	struct nmfield *result;	//resulting struct
	char *p;				//result for strtol
	int size=strlen(str)-1;
	int field;				//field number
	int i=0;				//char runner
	int j=0;				//current field number
	
	//get memory for resulting struct and assign start values
	result=(struct nmfield *) malloc(sizeof(struct nmfield));
	result->string=str;
	result->start=0;
	result->end=size;
	
	//convert string field position to numerical one
	field=strtol(cfield, &p, 10);
	if(*p!='\0') nm_error("'%s' is not a valid field number.");
	
	//from left
	//---
	if(cfield[0]!='-')
		for(i=0; i<=size; i++) {
			//set end if fieldend
			if(j==field && nm_check_partof(str[i], dels)==1)
				result->end=i-1; //-1 because we are at the delimiter
			//new field?
			if(nm_check_partof(str[i], dels)==1)
				j++;
			//set start if field at field
			if(j==field && nm_check_partof(str[i], dels)==1)
				result->start=i+1; //+1 because we are at the delimiter
		}
	//from right
	//---
	else
		for(i=size, field=field*(-1); i>=0; i--) {
			//set end if fieldend
			if(j==field && nm_check_partof(str[i], dels)==1)
				result->start=i+1; //+1 because we are at the delimiter
			//new field?
			if(nm_check_partof(str[i], dels)==1)
				j++;
			//set start if field at field
			if(j==field && nm_check_partof(str[i], dels)==1)
				result->end=i-1; //-1 because we are at the delimiter
		}
	
	return(result);
}

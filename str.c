/*
  *str.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "funcs.h"

//remove from pos1 to pos2 from str and return new string
//---
char *nm_str_delete(char* str, char* cpos1, char* cpos2) {
	//vars
	char *result;         //the returning string
	int pos1, pos2;       //the real positions
	int buff;             //buffer for pos-switching
	int i,j=0;            //runners
	int size=strlen(str); //size of string
	
	//make real positions
	if((pos1=nm_convert_pos(str, cpos1))==-1)
		nm_error("\'%s\' is not a valid position.", cpos1);
	if((pos2=nm_convert_pos(str, cpos2))==-1)
		nm_error("\'%s\' is not a valid position.", cpos2);
	
	//need to flip positions?
	if(pos1>pos2) {
		buff=pos1;
		pos1=pos2;
		pos2=buff;
	}
	
	//exit with NULL if whole string is to delete
	if(pos1==0 && pos2==size-1)
		return NULL;
	
	//create new string
	result=(char *) malloc(sizeof(char)  *(size+1-pos1+pos2));
	
	//fill new string
	for(i=0; i<size; i++) {
		if(i==pos1)
			i=pos2+1;
		result[j++]=str[i];
	}
	result[j]='\0';
	
	//it worked!
	return result;
}

//replace str1 with str2 in str and return new string
//---
char *nm_str_replace(char* path, char* str1, char* str2) {
	//vars
	//---
	int size;               //all the sizes
	int size1=strlen(str1);
	int size2=strlen(str2);
	char *i;                //runners
	char *j;
	char *k;
	char *l;
	char *result;           //resulting string
	
	//if size of new string is bigger,
	//so allocate memory for worst case scenario
	if(size2>size1)
		size=(strlen(path)/size1)*size2;
	else
		size=strlen(path);
	
	result=(char *) malloc(sizeof(char)  *size);
	
	//replace for all paths
	for(i=path, j=result; *i!='\0'; i++, j++) {
		//check if char is first char of str1
		//loop for str1 series
		while(*i==*str1) {
			//run till end or first char that is not the same
			for(k=str1, l=i; *k!='\0'; k++, l++)
				if(*k!=*l) break;
			
			//if k is at end replace
			if(*k=='\0') {
				//write str2 in str1's place
				for(k=str2; *k!='\0'; k++, j++)
					*j=*k;
				
				//jump i behind str1's occurence
				i+=sizeof(char)*size1;
			}
			else break;
		}
		*j=*i;
	}
	
	//add end if not allready there
	if(*j!='\0')
		*j='\0';
	
	return result;
}

//insert str at cpos
//---
char *nm_str_insert(char* path, char* str, char* cpos) {
	//vars
	//---
	char *result; //resulting string
	char *pos;    //position where to add
	char *i;      //runners
	char *j;
	char *k;
	
	//create resulting string
	result=(char *) malloc(sizeof(char)  *(strlen(path)+strlen(str)+1));
	
	//create position
	pos=&path[nm_convert_pos(path, cpos)];
	if(cpos[0]=='-')
		pos++;
	
	//fill new string
	for(i=path, j=result; *i!='\0'; i++, j++) {
		if(i==pos)
			for(k=str; *k!='\0'; k++, j++)
				*j=*k;
		*j=*i;
	}
	
	//position is at end?
	if(i==pos)
			for(k=str; *k!='\0'; k++, j++)
				*j=*k;
	
	//add end if not allready there
	if(*j!='\0')
		*j='\0';
	
	return result;
}

//convert str to camlcase (aa bb cc -> Aa Bb Cc)
//---
char *nm_str_case_camel(char* str) {
	//vars
	//---
	char *result;	//resulting var
	short word=0;	//inword status
	char *i=str;	//runner
	char *j;
	
	//create resulting string
	result=(char *) malloc(sizeof(char)  *(strlen(str)+1));
	j=result;
	
	//parse everything
	do {
		//beginning of a word?
		if(word==0 && nm_check_ws(*i)==0) {
			word=1;
			
			//convert small case to uppercase
			if(*i>='a' && *i<='z')
				*j=*i+'A'-'a';
			else
				*j=*i;
		}
		else {
			//check inword status
			if(word==1 && nm_check_ws(*i)==1)
				word=0;
			
			*j=*i;
		}
		
		//next char
		i++;
		j++;
	} while(*i!='\0');
	*j=*i;
	
	return(result);
}

//lower case everything
//---
char *nm_str_case_lower(char *str) {
	//vars
	//---
	char *result;	//resulting char
	char *i=str;	//runners
	char *j;
	
	//create resulting string
	result=(char *) malloc(sizeof(char)  *(strlen(str)+1));
	
	//lower case everything
	for(j=result; *i!='\0'; j++, i++)
		if(*i>='A' && *i<='Z')
			*j=*i+'a'-'A';
		else
			*j=*i;
	
	return(result);
}

//uppercase case everything
//---
char *nm_str_case_upper(char *str) {
	//vars
	//---
	char *result;	//resulting char
	char *i=str;	//runners
	char *j;
	
	//create resulting string
	result=(char *) malloc(sizeof(char)  *(strlen(str)+1));
	
	//upercase everything
	for(j=result; *i!='\0'; j++, i++)
		if(*i>='a' && *i<='z')
			*j=*i+'A'-'a';
		else
			*j=*i;
	
	return(result);
}

char *nm_str_delete_field(char *str, char *cnum, char *dels) {
	//vars
	//---
	char *result;	//resulting char
	int field;		//field to delete
	int size=strlen(str)-1;
	int ps=0;		//start position for deleting
	int pe=size+1; 	//end position for deleting
	int i;			//runners
	int j=0;
	
	//convert cnum to field
	field=strtol(cnum, &result, 10);
	if(*result!='\0') nm_error("'%s' is not a valid field number.");
	
	//from left
	if(cnum[0]!='-')
		for(i=0; i<=size; i++) {
			//set end if fieldend
			if(j==field && nm_check_partof(str[i], dels)==1)
				pe=i;
			//new field?
			if(nm_check_partof(str[i], dels)==1)
				j++;
			//set start if field at field
			if(j==field && nm_check_partof(str[i], dels)==1)
				ps=i;
		}
	//from right
	else
		for(i=size, field=field*(-1); i>=0; i--) {
			//set end if fieldend
			if(j==field && nm_check_partof(str[i], dels)==1)
				ps=i;
			//new field?
			if(nm_check_partof(str[i], dels)==1)
				j++;
			//set start if field at field
			if(j==field && nm_check_partof(str[i], dels)==1)
				pe=i;
		}
	
	//return string if no field to delete
	if(ps==0 && pe==size+1)
		return(str);
	
	//create result
	result=(char *) malloc(sizeof(char) * (strlen(str)-pe+ps));
	
	//assign str to result
	for(i=0, j=0; i<=size; i++, j++) {
		//skip field
		if(i==ps) i=pe;
		
		result[j]=str[i];
	}
	if(result[j]!='\0')
		result[j]='\0';
		
	return(result);
}

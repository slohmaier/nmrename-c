/*
 * str.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "funcs.h"

//remove from pos1 to pos2 from str and return new string
//---
char *nm_str_delete(char* str, char* cpos1, char* cpos2, char *null1) {
	//vars
	//---
	char *result;         //the returning string
	int pos1, pos2;       //the real positions
	int buff;             //buffer for pos-switching
	int i,j=0;            //runners
	int size=strlen(str); //size of string
	
	//convert the positions from strings into real numbers, exit on error.
	if((pos1=nm_convert_pos(str, cpos1))==-1)
		nm_error("\'%s\' is not a valid position.", cpos1);
	if((pos2=nm_convert_pos(str, cpos2))==-1)
		nm_error("\'%s\' is not a valid position.", cpos2);
	
	//switch positions if 2nd position is smaller than first
	if(pos1>pos2) {
		buff=pos1;
		pos1=pos2;
		pos2=buff;
	}
	
	//return error if whole filename would be deleted
	if(pos1==0 && pos2==size-1)
		return NULL;
	
	//get memory for resulting string
	result=(char *) malloc(sizeof(char)  *(size+1-pos1+pos2));
	
	//assign new string char by char
	for(i=0; i<size; i++) {
		//skip the part that should be deleted
		if(i==pos1)
			i=pos2+1;
			
		result[j++]=str[i];
	}
	result[j]='\0';
	
	//return new filename
	return result;
}

//replace str1 with str2 in str and return new string
//---
char *nm_str_replace(char* path, char* str1, char* str2, char *null1) {
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
	
	//Determine size of string for the worst case
	if(size2>size1)
		size=(strlen(path)/size1)*size2;
	else
		size=strlen(path);
	
	//get memory for the resulting char
	result=(char *) malloc(sizeof(char)  *size);
	
	//assign resulting filename char by char
	for(i=path, j=result; *i!='\0'; i++, j++) {
		//if current char is 1st char of the replaced string investigate
		//further
		while(*i==*str1) {
			//check char by char if i is the start for the replaced string
			for(k=str1, l=i; *k!='\0'; k++, l++)
				if(*k!=*l) break;
			
			//if the check went to \0 we have to replace the string now
			if(*k=='\0') {
				//write the replacing string in the place of the replaced
				//one
				for(k=str2; *k!='\0'; k++, j++)
					*j=*k;
				
				//continue where the replaced string ends
				i+=sizeof(char)*size1;
			}
			else break;
		}
		
		*j=*i;
	}
	
	if(*j!='\0')
		*j='\0';
	
	return result;
}

//insert str at cpos
//---
char *nm_str_insert(char* path, char* str, char* cpos, char *null1) {
	//vars
	//---
	char *result; //resulting string
	char *pos;    //position where to add
	char *i;      //runners
	char *j;
	char *k;
	
	//get memory for resulting string (orig. filename + the inserted string)
	result=(char *) malloc(sizeof(char) * (strlen(path) + strlen(str)+1));
	
	//convert the string position into an numerical on
	pos=&path[nm_convert_pos(path, cpos)];
	
	//correct position if from right so from right behaves like from left
	if(cpos[0]=='-')
		pos++;
	
	//fill new string
	for(i=path, j=result; *i!='\0'; i++, j++) {
		//if we are at the insert position insert string char by char
		if(i==pos)
			for(k=str; *k!='\0'; k++, j++)
				*j=*k;
		
		*j=*i;
	}
	
	//if the position is at the end the loop missed it.
	if(i==pos)
			for(k=str; *k!='\0'; k++, j++)
				*j=*k;
	
	if(*j!='\0')
		*j='\0';
	
	return result;
}

//convert str to camlcase (aa bb cc -> Aa Bb Cc)
//---
char *nm_str_case_camel(char* str, char *null1, char *null2, char *null3) {
	//vars
	//---
	char *result;	//resulting var
	short word=0;	//inword status
	char *i=str;	//runner
	char *j;
	
	//get memory for resulting string
	result=(char *) malloc(sizeof(char) * (strlen(str)+1));
	j=result;
	
	do {
		//Beginning of a word?
		if(word==0 && nm_check_ws(*i)==0) {
			word=1;
			
			//Convert small case to upper case
			if(*i>='a' && *i<='z')
				*j=*i+'A'-'a';
			else
				*j=*i;
		}
		else {
			//If we were in a word and are no longer set wordstatus
			if(word==1 && nm_check_ws(*i)==1)
				word=0;
			
			*j=*i;
		}
		
		//next char
		i++;
		j++;
	} while(*i!='\0');
	
	*j='\0';
	
	return(result);
}

//lower case everything
//---
char *nm_str_case_lower(char *str, char *null1, char *null2, char *null3) {
	//vars
	//---
	char *result;	//resulting char
	char *i=str;	//runners
	char *j;
	
	//get memory for resulting string
	result=(char *) malloc(sizeof(char) * (strlen(str)+1));
	
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
char *nm_str_case_upper(char *str, char *null1, char *null2, char *null3) {
	//vars
	//---
	char *result;	//resulting char
	char *i=str;	//runners
	char *j;
	
	//get memory for resulting string
	result=(char *) malloc(sizeof(char) * (strlen(str)+1));
	
	//upercase everything
	for(j=result; *i!='\0'; j++, i++)
		if(*i>='a' && *i<='z')
			*j=*i+'A'-'a';
		else
			*j=*i;
	
	return(result);
}

//delete field cnum from str. fields delimiters are in dels.
//---
char *nm_str_delete_field(char *str, char *cnum, char *dels, char *null1) {
	//vars
	//---
	char *result;	//resulting char
	struct nmfield *field;
	int i;			//runners
	int size=strlen(str)-1;
	int j=0;		//runner for current field
	
	//convert field into integers
	field=nm_convert_field(str, cnum, dels);
	
	//return string if no field to delete
	if(field->start==0 && field->end==size)
		return(str);
	
	//get memory for resulting string
	result=(char *) malloc(sizeof(char) * (strlen(str)-field->end+field->start-1));
	
	//assign str to result
	for(i=0, j=0; i<=size; i++, j++) {
		//skip the deleted field
		if(i==field->start) {
			//if field is at the end use the delimiter in front of the field
			if(field->end==size) {
				result[j]=str[i-1];
				i=field->end+1;
			}
			//skip it
			else
				i=field->end+2;
		}
		result[j]=str[i];
	}
	
	if(result[j]!='\0')
		result[j]='\0';
	
	free(field);
		
	return(result);
}

//switch field f1 with field f2. fields delimiters are in dels.
//---
char *nm_str_switch_field(char *str, char *f1, char *f2, char *dels) {
	//vars
	//---
	char *result;	//resulting char;
	struct nmfield *field1, *field2; //the 2 fields
	int size=strlen(str);
	int i;			//runners
	int j;
	int k;
	
	//convert fields into integers
	field1=nm_convert_field(str, f1, dels);
	field2=nm_convert_field(str, f2, dels);
	
	//get memory for result
	result=(char *) malloc(sizeof(char) * size);
	
	printf("f1: %d|%d  f2: %d|%d  size:%d\n\n", field1->start, field1->end, field2->start, field2->end, size);
	
	//assign result
	for(i=0, j=0; i<=size; i++, j++) {
		if(i==field1->start) {
			for(k=field2->start, i=field1->end; k<=field2->end; k++, j++) {
				result[j]=str[k];
				printf("i:%d j:%d k:%d char:%c\n", i, j, k, str[k]);
			}
			j--; //j gets increased by the for loop, but j should remain the same
		}
		else if(i==field2->start) {
			for(k=field1->start, i=field2->end; k<=field1->end; k++, j++) {
				result[j]=str[k];
				printf("i:%d j:%d k:%d char:%c\n", i, j, k, str[k]);
			}
			j--; //j gets increased by the for loop, but j should remain the same
		}
		else {
			result[j]=str[i];
			printf("i:%d j:%d k:  char:%c\n", i, j, str[i]);
		}
	}
	result[j]=str[i];
	
	return result;
}

char *nm_str_delete_str(char *path, char *str, char *null1, char *null2) {
	return(nm_str_replace(path, str, "", NULL));
}

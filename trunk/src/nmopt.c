/*
 * nmopt.c
 * This file is part of nmrename
 *
 * Copyright (C) 2007-2010 Stefan Lohmaier
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

#include "nmopt.h"
#include "msg.h"
#include "string.h"

struct nmopts *nmopt(char **argv, int argc, struct nmopts *options, int *index) {
	struct nmopts *result = options;
	*index=*index+1;
	
	//exit if at end
	if(*index >= argc) return NULL;
	
	for(; result->option != NULL; ++result) {
		if(strcmp(argv[*index], result->option) == 0)
			return result;
	}
	
	//So no match was found? return the error structure.
	return(result);
}


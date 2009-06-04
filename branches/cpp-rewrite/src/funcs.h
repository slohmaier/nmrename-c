/*
 * funcs.h
 * This file is part of nmrename
 *
 * Copyright (C) 2007-2009 Stefan Lohmaier
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

unsigned short is_path(char *path);
int nm_convert_pos(char *str, char* cpos);
short nm_check_ws(char c);
short nm_check_partof(char c, char *string);

//struct for a field
struct nmfield {
	char *string;
	int start;
	int end;
};

struct nmfield *nm_convert_field(char *str, char *cfield, char *dels);

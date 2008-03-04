/*
 * cmd.h
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

char **nm_delete(char* *pathlist, int pathno, char* cpos1, char* cpos2);
char **nm_replace_str(char **pathlist, int pathno, char *str1, char* str2);
char **nm_delete_str(char **pathlist, int pathno, char *str);
char **nm_insert_str(char **pathlist, int pathno, char *str, char* cpos);
char **nm_camel_case_str(char **pathlist, int pathno);
char **nm_upper_case_str(char **pathlist, int pathno);
char **nm_lower_case_str(char **pathlist, int pathno);
char **nm_delete_field(char **pathlist, int pathno, char *cnum, char *dels);
char **nm_switch_field(char **pathlist, int pathno, char *f1, char *f2, char *dels);

/*
 * str.h
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

char *nm_str_replace(char* path, char* str1, char* str2, char *null1);
char *nm_str_delete(char* str, char* cpos1, char* cpos2, char *null1);
char *nm_str_insert(char* path, char* str, char* cpos, char *null1);
char *nm_str_case_camel(char *str, char *null1, char *null2, char *null3);
char *nm_str_case_lower(char *str, char *null1, char *null2, char *null3);
char *nm_str_case_upper(char *str, char *null1, char *null2, char *null3);
char *nm_str_delete_field(char *str, char *cnum, char *dels, char *null1);
char *nm_str_switch_field(char *str, char *f1, char *f2, char *dels);
char *nm_str_delete_str(char *path, char *str, char *null1, char *null2);
char *nm_str_list(char *path, char *list, char *null1, char *null2);
#ifdef WITH_EXIF
char *nm_str_exif(char *path, char *pattern, char *null1, char *null2);
#endif

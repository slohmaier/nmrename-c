/*
 * msg.c
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
#include <stdarg.h>
#include <stdlib.h>
#include "msg.h"

//Patterns for the messages
#define VERSION "0.1"
#define MSG ">> "
#define MSG_WARNING "\033[33mW> \033[m"
#define MSG_ERROR "\033[31mE> \033[m"

//print a normal message
void nm_msg(const char *format, ...) {
	va_list list;
	va_start(list, format);
	printf(MSG);
	vprintf(format, list);
	printf("\n");
}

//print a warning
void nm_warn(const char *format, ...) {
	va_list list;
	va_start(list, format);
	printf(MSG_WARNING);
	vprintf(format, list);
	printf("\n");
}

//print a normal message
void nm_error(int code, const char *format, ...) {
	va_list list;
	va_start(list, format);
	printf(MSG_ERROR);
	vprintf(format, list);
	printf("Try nmrename -h.\n");
	if(code != 0)
		exit(code);
}

//print help
void nm_help(void) {
	printf(
		"\n"
		"nmrename %s - A mass renaming tool.\n"
		"Copyright 2007 by Stefan Lohmaier <noneuss at gmail dot com>\n"
		"\n"
		"Usage:\n"
		"    nmrename [PATHLIST] [COMMANDS]\n"
		"\n"
		"  [PATHLIST] is a list of the paths (dirs and files) you want to rename.\n"
		"  [COMMANDS] is a list of commands that will be executed one by one.\n"
		"\n"
		"COMMANDS:\n"
		"  -h    : Print this text.\n"
		"  -f    : Renames without asking. Use with CAUTION!\n"
		"  -c    : Clear the pathlist.\n"
		"\n"
		"  -cc   : Camelcase (e.g. hallo -> Hallo)\n"
		"  -cu   : Uppercase (e.g. hallo -> HALLO)\n"
		"  -cl   : Lowercase (e.g. HALLO -> hallo)\n"
		"\n"
		"  -d [POS1] [POS2] : Remove from POS1 to POS2.\n"
		"\n"
		"  -sr [S1] [S2]    : Replace all occurences of S1 with S2.\n"
		"  -sd [S]          : Delete all occurences of S.\n"
		"  -si [S] [POS]    : Insert S at POS.\n"
		"\n"
		"  -fd [POS] [S]         : Deletes field POS. Fielddelimiters are in S.\n"
		"  -fs [POS1] [POS2] [S] : Switches field POS1 with field POS2.\n"
		"                          Fielddelimiters are in S.\n"
		"\n"
		"  [POS*] can be 0,1,2,... or -0,-1,-2,... ('-' starts counting from the right).\n"
		"  [S*] is a string of your choice.\n"
		"\n", VERSION
	);
}

/*
 * cmd.h
 * This file is part of nmrename
 *
 * Copyright (C) 2007-2010 Stefan Lohmaier
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

enum enumnmcmd {
	nmcmderror=0,
	#ifdef WITH_EXIF
	nmcmdexif,
	#endif
	nmcmdclear,
	nmcmdhelp,
	nmcmddelete,
	nmcmdstrreplace,
	nmcmdstrdelete,
	nmcmdstrinsert,
	nmcmdstrcasecamel,
	nmcmdstrcaseupper,
	nmcmdstrcaselower,
	nmcmdfielddelete,
	nmcmdfieldswitch,
	nmcmdlist,
	nmcmdforce
};
typedef enum enumnmcmd nmcmd;

void nmrename(char **pathlist, int pathno, nmcmd cmd, char *cmdtext, char *arg1, char *arg2, char *arg3);


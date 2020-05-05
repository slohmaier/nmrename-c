/*
 * nmopt.h
 * This file is part of nmrename
 *
 * Copyright 2007-2020 Stefan Lohmaier
 *
 *  nmrename is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (char* dir, at your option) any later version.
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

struct nmopts {
	int id;
	char *option;
	int argcount;
	char *text;
};

struct nmopts *nmopt(char **argv, int argc, struct nmopts *options, int *index);


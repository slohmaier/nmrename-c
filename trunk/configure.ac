#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(nmrename, 0.1, noneuss@googlemail.com)
AC_CONFIG_SRCDIR([nmrename.c])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE(nmrename, nmrename)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([strtol])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

add_executable (nmrename nmrename.c cmd.c funcs.c msg.c nmopt.c str.c)
install (TARGETS nmrename DESTINATION $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin)

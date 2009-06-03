#
# Configuration
#
CFLAGS ?= -g -Wall -O0
LDFLAGS ?=
CC ?= gcc
PREFIX ?=/usr
DESTDIR ?=

####################################
#         !!! ATTENTION !!!        #
#                                  #
# Change NOTHING below this point! #
####################################
PROGRAM=nmrename
OBJECTS=$(subst src/,build/,$(subst .c,.o,$(wildcard src/*.c)))
DEFINES=

#check if libexif exists
ifeq ($(shell pkg-config libexif --exists || echo failed),failed)
	WARN+=$(warning libexif is missing! Install libexif-dev or get it from http://libexif.sourceforge.net/.)
else
	CFLAGS += $(strip $(shell pkg-config libexif --cflags))
	LDFLAGS += $(strip $(shell pkg-config libexif --libs))
	DEFINES += |WITH_EXIF
endif

#add defines to cflags
CFLAGS += $(strip $(subst |, -D,$(DEFINES)))

all: errors $(PROGRAM)
	@echo

errors:
	$(WARN)
	$(ERR)
	@echo
	@echo Starting build of $(PROGRAM):

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m755 build/$(PROGRAM) $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)

clean:
	@echo
	@echo Deleting build objects and programs.
	rm -rf build

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o build/$(PROGRAM) $(subst src/,build/,$(OBJECTS))

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

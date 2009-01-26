#
# Configuration
#
CFLAGS= -g -Wall
CC=gcc $(CFLAGS)
PREFIX=/usr

####################################
#         !!! ATTENTION !!!        #
#                                  #
# Change NOTHING below this point! #
####################################
PROGRAM=nmrename
OBJECTS=$(subst .c,.o,$(wildcard src/*.c))

all: $(PROGRAM)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m755 build/$(PROGRAM) $(DESTDIR)$(PREFIX)/bin/$(PROGRAM)

clean:
	rm -rf build

$(PROGRAM): $(OBJECTS)
	$(CC) -o build/$(PROGRAM) $(subst src/,build/,$(OBJECTS))

%.o: %.c
	@mkdir -p $(dir $(subst src,build,$@))
	$(CC) -c $< -o $(subst src,build,$@)

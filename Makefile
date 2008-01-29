CC=gcc
#CFLAGS=-Wall -g
CFLAGS=-O2
OBJECTS=main.o msg.o funcs.o cmd.o str.o
PREFIX=/usr

all: $(OBJECTS)
	$(CC) -o nmrename $(OBJECTS)

.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f *.o nmrename

install:
	mkdir -p $(DESTDIR)/$(PREFIX)/bin/
	install -m 755 nmrename $(DESTDIR)/$(PREFIX)/bin/

uninstall:
	rm -f $(DESTDIR)/$(PREFIX)/bin/

CC=gcc --std=c11
CFLAGS=`pkg-config --libs --cflags x11 freetype2 xft fontconfig`

.PHONY : all install uninstall

all: xftwidth

xftwidth: xftwidth.c
	$(CC) $(CFLAGS) -o $@ $< 

install: xftwidth
	install -D -m 0755 xftwidth ${DESTDIR}/usr/bin/xftwidth

uninstall:
	rm ${DESTDIR}/usr/bin/xftwidth

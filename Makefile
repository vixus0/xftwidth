CC=gcc
CFLAGS=--std=c11 `pkg-config --cflags x11 freetype2 xft fontconfig`
LDFLAGS=`pkg-config --libs x11 freetype2 xft fontconfig`

.PHONY : all install uninstall

all: xftwidth

xftwidth: xftwidth.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

install: xftwidth
	install -D -m 0755 xftwidth ${DESTDIR}/usr/bin/xftwidth

uninstall:
	rm ${DESTDIR}/usr/bin/xftwidth

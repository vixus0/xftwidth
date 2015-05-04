CC=gcc --std=c11
CFLAGS=`pkg-config --libs --cflags x11 freetype2 xft fontconfig`

.PHONY : all install uninstall

all: xftwidth xftsize

xftwidth: xftwidth.c
	$(CC) $(CFLAGS) -o $@ $< 

xftsize: xftsize.c
	$(CC) -g $(CFLAGS) -o $@ $< 

install: xftwidth xftsize
	install -D -m 0755 xftwidth ${DESTDIR}/usr/bin/xftwidth
	install -D -m 0755 xftsize ${DESTDIR}/usr/bin/xftsize

uninstall:
	rm ${DESTDIR}/usr/bin/xftwidth
	rm ${DESTDIR}/usr/bin/xftsize

CC=gcc --std=c11
CFLAGS=`pkg-config --libs --cflags x11 freetype2 xft fontconfig`

xftwidth: xftwidth.c
	$(CC) $(CFLAGS) -o $@ $< 

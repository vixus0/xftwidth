CC=gcc --std=c11
CFLAGS=`pkg-config --libs --cflags x11 freetype2 xft fontconfig`

all: xftwidth xftsize

xftwidth: xftwidth.c
	$(CC) $(CFLAGS) -o $@ $< 

xftsize: xftsize.c
	$(CC) -g $(CFLAGS) -o $@ $< 

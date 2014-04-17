CC=gcc
CFLAGS=$(shell pkg-config --libs --cflags x11 xft fontconfig)

xftwidth: xftwidth.c
	$(CC) -o $@ $< $(CFLAGS)

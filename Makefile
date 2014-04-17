CC=gcc
CFLAGS=$(shell pkg-config --libs --cflags x11 xft fontconfig)

xftwidth: src/xftwidth.c
	$(CC) -o $@ $< $(CFLAGS)

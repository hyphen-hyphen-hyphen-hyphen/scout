CC ?= gcc


all: scout

scout: scout.c
	$(CC) scout.c -o -lcjson scout


install: all
	install scout /usr/local/bin/scout -m 755

.PHONY: all install

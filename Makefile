CC ?= gcc


all: scout

scout: src/scout.c
	gcc -Isrc -lcjson src/scout.c src/mathyy/mathyy.c -o scout


install: all
	install scout /usr/local/bin/scout -m 755

.PHONY: all install

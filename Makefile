CC=/usr/bin/gcc
CFLAGS=-Wall -Werror -O0 -pedantic -std=c99 -Iinclude
SOURCES=src/main.c src/chunk.c src/memory.c src/debug.c src/value.c

clox: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean: clox
	rm clox

tags: $(SOURCES)
	fdfind --extension c --extension h | xargs ctags

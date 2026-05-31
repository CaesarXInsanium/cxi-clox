CC=/usr/bin/gcc
CFLAGS=-Wall -Werror -O0 -pedantic -ggdb -std=c99 -Iinclude
SOURCES=src/main.c src/chunk.c src/memory.c src/debug.c src/value.c src/vm.c src/compiler.c src/scanner.c

clox: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

clean: clox
	rm clox

tags: $(SOURCES)
	fdfind --extension c --extension h | xargs ctags

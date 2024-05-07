CC = gcc
DIR_SRC = ./lib/src
DIR_BIN = ./lib/bin

DIR_HEAD = ./lib/headers
DIR_FILE = ./compress
CFLAGS = -Wall -fPIC

all: $(DIR_FILE)/compressor.out $(DIR_FILE)/try.out

$(DIR_FILE)/try.out: $(DIR_FILE)/try.o $(DIR_BIN)/libcompress.so
	$(CC) $(CFLAGS) -o $@ $<  -L$(DIR_BIN) -lcompress -Wl,-rpath,$(DIR_BIN)

$(DIR_FILE)/try.o: $(DIR_FILE)/try.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_FILE)/compressor.out: $(DIR_FILE)/compressor.o $(DIR_BIN)/libcompress.so
	$(CC) $(CFLAGS) -o $@ $<  -L$(DIR_BIN) -lcompress -Wl,-rpath,$(DIR_BIN)

$(DIR_FILE)/compressor.o: $(DIR_FILE)/compressor.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/compress.o: $(DIR_SRC)/compress.c $(DIR_HEAD)/compress.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/vector.o: $(DIR_SRC)/vector.c $(DIR_HEAD)/vector.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/trie.o: $(DIR_SRC)/trie.c $(DIR_HEAD)/trie.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/set.o: $(DIR_SRC)/set.c $(DIR_HEAD)/set.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/map.o: $(DIR_SRC)/map.c $(DIR_HEAD)/map.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/list.o: $(DIR_SRC)/list.c $(DIR_HEAD)/list.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/que.o: $(DIR_SRC)/que.c $(DIR_HEAD)/que.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/tree.o: $(DIR_SRC)/tree.c $(DIR_HEAD)/tree.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/avl.o: $(DIR_SRC)/avl.c $(DIR_HEAD)/avl.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SRC)/hash.o: $(DIR_SRC)/hash.c $(DIR_HEAD)/hash.h
	$(CC) $(CFLAGS) -c $< -o $@


$(DIR_BIN)/libcompress.so: $(DIR_SRC)/compress.o $(DIR_SRC)/vector.o $(DIR_SRC)/list.o $(DIR_SRC)/que.o $(DIR_SRC)/tree.o $(DIR_SRC)/avl.o $(DIR_SRC)/hash.o $(DIR_SRC)/trie.o $(DIR_SRC)/set.o $(DIR_SRC)/map.o 
	$(CC) $(CFLAGS) -shared -o $@ $^

clean:
	rm $(DIR_FILE)/compressor.o
	rm $(DIR_SRC)/compress.o
	rm $(DIR_SRC)/trie.o
	rm $(DIR_SRC)/set.o
	rm $(DIR_SRC)/map.o
	rm $(DIR_SRC)/vector.o
	rm $(DIR_SRC)/que.o
	rm $(DIR_SRC)/tree.o
	rm $(DIR_SRC)/avl.o
	rm $(DIR_SRC)/hash.o
	rm $(DIR_SRC)/list.o
	rm $(DIR_SRC)/try.o
	rm $(DIR_BIN)/libcompress.so
	rm $(DIR_FILE)/output.txt

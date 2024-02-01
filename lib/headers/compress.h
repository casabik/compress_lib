#ifndef COMPRESS_H
#define COMPRESS_H

#include <stdio.h>

typedef enum {
	COMPRESS_TYPE_RLE,
	COMPRESS_TYPE_FIBONACCI
} CompressType;

typedef struct {
	CompressType mode;
	int n;
	int *data;
} CompressedData;

extern CompressedData compress(CompressType mode, int n, int *data);
extern CompressedData rle_compress(int n, int *data);
extern CompressedData fib_compress(int n, int *data);


#endif


#ifndef COMPRESS_H
#define COMPRESS_H

#include <stdio.h>

typedef enum {
	COMPRESS_TYPE_RLE,
	COMPRESS_TYPE_FIBONACCI,
	COMPRESS_TYPE_SIMPLE9
} CompressType;

typedef struct {
	CompressType mode;
	int n;
	int *data;
} CompressedData;

extern CompressedData decompress(CompressType mode, int n, int *data);
extern CompressedData compress(CompressType mode, int n, int *data);
extern CompressedData rle_compress(int n, int *data);
extern CompressedData fib_compress(int n, int *data);
extern CompressedData simp_compress(int n, int *data);
extern CompressedData rle_decompress(int n, int *data);
extern CompressedData fib_decompress(int n, int *data);
extern CompressedData simp_decompress(int n, int *data);

#endif


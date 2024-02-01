#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/compress.h"



CompressedData compress(CompressType mode, int n, int *data) {
	CompressedData compressed;
	compressed.mode = mode;
	compressed.n = n;
	compressed.data = data;
	int *list;
	list = calloc(2 * (compressed.n), sizeof(*list));
	if (list == NULL) {
	        exit(1);
        }
	if (compressed.mode == COMPRESS_TYPE_RLE) {
		int count_temp = 1;
		int temp = 0;
		for (int i = 1; i < compressed.n; i++) {
			if ((compressed.data)[i] == (compressed.data)[i - 1]) {
				count_temp++;
			} else {
				list[temp] = (compressed.data)[i - 1];
				temp++;
				list[temp] = count_temp;
				temp++;
				count_temp = 1;
			}
		}
		list[temp] = (compressed.data)[compressed.n - 1];
		temp++;
		list[temp] = count_temp;
		temp++;
		compressed.data = list;
		compressed.n = temp;

	} else if(compressed.mode == COMPRESS_TYPE_FIBONACCI) {
		int fibonacci[12] = {233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1};
		for (int i = 0; i < n; ++i) {
			int number = (compressed.data)[i];
			int index = 0;
			int result = 0;
			while (number != 0) {
				while (fibonacci[index] > number) {
					index++;
				}
				int temp = 1;
				for (int i = 0; i < (11 - index); i++) {
					temp *= 10;
				}
				result += temp;
				number -= fibonacci[index];
				index++;
			}
			list[i] = result;
		}
		compressed.data = list;
	}
	return compressed;
}

CompressedData
rle_compress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_RLE;
	return compress(mode, n, data);
}

CompressedData
fib_compress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_FIBONACCI;
	return compress(mode, n, data);
}

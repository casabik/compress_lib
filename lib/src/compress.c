#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/compress.h"

#define BLOCK_SIZE 32
#define MODE_BITS 4

int check_number_length(int number) {
    int length = 0;
    unsigned int num = number;
    while (num > 0) {
        length++;
        num >>= 1;
    }
    return length;
}
int find_mode_by_length(int length) {
    int mode;
    if (length <= 1) {
        mode = 0;
    } else if (length <= 2) {
        mode = 1;
    } else if (length <= 3) {
        mode = 2;
    } else if (length <= 4) {
        mode = 3;
    } else if (length <= 5) {
        mode = 4;
    } else if (length <= 7) {
        mode = 5;
    } else if (length <= 9) {
        mode = 6;
    } else if (length <= 14) {
        mode = 7;
    } else {
        mode = 8;
    }
    return mode;
}

CompressedData decompress(CompressType mode, int n, int *data) {
	CompressedData compressed;
	compressed.mode = mode;
	compressed.n = n;
	compressed.data = data;
	int *list;
	list = calloc(compressed.n * 9, sizeof(*list));
	if (compressed.mode == COMPRESS_TYPE_RLE) {
		int count = 0;
		for (int i = 0; i < compressed.n; i = i + 2) {
			int range = compressed.data[i + 1];
			int number = ((int*)compressed.data)[i];
			for(int j = 0; j < range; j++) {
				list[count] = number;
				count++;
			}
		}
		compressed.data = list;
		compressed.n = count;
	} else if(compressed.mode == COMPRESS_TYPE_FIBONACCI) {
		int fibonacci[12] = {233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1};
		int count = 0;
		for (int i = 0; i < compressed.n; i++) {
			int temp = compressed.data[i];
			int temp_value = 0;
			int index = 11;
			while (temp > 0) {
				if (temp % 10 == 1) {
					temp_value += fibonacci[index];
				}
				temp /= 10;
				index--;
			}
			list[count] = temp_value; 
			count++;
		}
		compressed.data = list;
		compressed.n = count;
	} else if (compressed.mode == COMPRESS_TYPE_SIMPLE9) {
		int count = 0;
		int modes_list[9] = {1, 2, 3, 4, 5, 7, 9, 14, 28};
		for (int i = 0; i < compressed.n; ++i) {
			int block = compressed.data[i];
			int mode = (block >> (BLOCK_SIZE - MODE_BITS)) & ((1 << MODE_BITS) - 1);
			int size = modes_list[mode];
			int mask = (1 << size) - 1;
			for (int i = 0; i < (BLOCK_SIZE - MODE_BITS) / size; ++i) {
				int shift_amount = BLOCK_SIZE - MODE_BITS - size * (i + 1);
				list[count++] = (block >> shift_amount) & mask;
			}
		}
		compressed.data = list;
		compressed.n = count;
	}
	return compressed;
}


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
	} else if (compressed.mode == COMPRESS_TYPE_SIMPLE9) {
		int *temp_list = calloc(compressed.n, sizeof(*temp_list));
        int *list = calloc(compressed.n, sizeof(*list));
		int currentNumber = 0; // Текущее число для кодировки
		int temp = 0; // временная переменная типка i
		int block = 0;
		unsigned int mode = 0;
		int point = 0;
		int modes_list[9] = {1, 2, 3, 4, 5, 7, 9, 14, 28};
		int flag_check = 0;
		while (point < compressed.n) {
			int number = compressed.data[point];
			int length = check_number_length(number);
			unsigned int new_mode = find_mode_by_length(length);
			if (new_mode > mode) {
				if ((temp + 1) * modes_list[new_mode] >= BLOCK_SIZE  - MODE_BITS) {
					flag_check++;
					point--;
				} else {
					mode = new_mode;
					temp_list[temp++] = number;
				}
			} else {
				if ((temp + 1) * modes_list[mode] >= BLOCK_SIZE - MODE_BITS) {
					flag_check++;
					point--;
				} else {
					temp_list[temp++] = number;
				}
			}

			if (flag_check != 0) {
				int shift_amount = BLOCK_SIZE - MODE_BITS;
				currentNumber |= (mode << shift_amount);
				for (int j = 0; j < temp; j++) {
					shift_amount -= modes_list[mode];
        			currentNumber |= (temp_list[j] << shift_amount);
				}
				list[block] = currentNumber;
				block++;
				point += temp;
				mode = 0;
				currentNumber = 0;
				flag_check = 0;
			}
			point++;
		}
		compressed.data = list;
		compressed.n = block;
    }
	return compressed;
}




CompressedData
rle_compress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_RLE;
	return compress(mode, n, data);
}

CompressedData
rle_decompress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_RLE;
	return decompress(mode, n, data);
}

CompressedData
fib_compress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_FIBONACCI;
	return compress(mode, n, data);
}

CompressedData
fib_decompress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_FIBONACCI;
	return decompress(mode, n, data);
}

CompressedData
simp_compress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_SIMPLE9;
	return compress(mode, n, data);
}

CompressedData
simp_decompress(int n, int *data) {
	CompressType mode = COMPRESS_TYPE_SIMPLE9;
	return decompress(mode, n, data);
}

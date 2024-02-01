#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/compress.h"
#include "../lib/headers/vector.h"

enum {
	LENGHT = 10000
};

void fib_decode(CompressedData c) {
        FILE *output;
	int fibonacci[12] = {233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1};
        output = fopen("./compress/output_rle.txt", "w");
	for (int i = 0; i < c.n; i++) {
		int temp = c.data[i];
		int temp_value = 0;
		int index = 11;
		while (temp > 0) {
			if (temp % 10 == 1) {
				temp_value += fibonacci[index];
			}
			temp /= 10;
			index--;
		}
		fprintf(output, "%c", temp_value);
	}
	fclose(output);
}

void rle_decode(CompressedData c) {
	FILE *output;
        output = fopen("./compress/output_fib.txt", "w");
        for (int i = 0; i < c.n; i = i + 2) {
		int range = c.data[i + 1];
		int number =((int*)c.data)[i];
		for(int j = 0; j < range; j++) {
               		fprintf(output, "%c", number);
		}
        }
        fclose(output);
}

int
main(void) {
	FILE *input;
	input = fopen("./compress/input.txt", "r");
	Vector vector;
	init(&vector);
	int cur;
	while((cur = getc(input)) != EOF) {
		v_push_back(&vector, (int)cur);
	}
	CompressedData compressed_output_rle = rle_compress(vector.size, vector.data);
	CompressedData compressed_output_fib = fib_compress(vector.size, vector.data);
	v_free(&vector);
	if (compressed_output_rle.data == NULL || compressed_output_fib.data == NULL) {
		printf("error");
	}
	fib_decode(compressed_output_fib);
	rle_decode(compressed_output_rle);
	fclose(input);
	return 0;
}

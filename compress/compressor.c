#include <stdio.h>
#include <stdlib.h>
#include "../lib/headers/compress.h"
#include "../lib/headers/vector.h"

enum {
	LENGHT = 10000
};

void output(CompressedData c) {
	FILE *output;
	output = fopen("./compress/output.txt", "w");
	for (int i = 0; i < c.n; i++) {
		fprintf(output, "%c", c.data[i]);
	}
	fclose(output);
}

int
main(void) {
	FILE *input;
	input = fopen("./compress/input.txt", "r");
	Vector vector;
	v_init(&vector);
	int cur;
	while((cur = getc(input)) != EOF) {
		v_push_back(&vector, (int)cur);
	}
	CompressedData compressed = fib_compress(vector.size, vector.data);
	CompressedData compressed_output = fib_decompress(compressed.n, compressed.data);
	v_free(&vector);
	if (compressed_output.data == NULL) {
		printf("error");
	}
	output(compressed_output);
	fclose(input);
	return 0;
}

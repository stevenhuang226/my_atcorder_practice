/*
 * Auth: stevenhuang.dog@gmail.com
 * Help: chatgpt, official solution
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main()
{
	int size;
	scanf("%" SCNd32, &size);

	int ex = 14;
	int res[ex][ex];
	int above[ex];
	int prefix[ex];

	for (int i = 0; i < ex; ++i) {
		for (int i2 = 0; i2 < ex; ++i2) {
			res[i][i2] = 0;
		}
		above[i] = 0;
		prefix[i] = 0;
	}

	for (int r = 1; r < size; ++r) {
		prefix[0] = above[0];
		for (int c = 0; c < size - 1; ++c) {
			res[r][c] = prefix[c+2] - above[c] + 1;
			above[c] += res[r][c];
		}

		for (int c = 0; c < size; ++c) {
			prefix[c + 1] = prefix[c] + res[r][c];
		}
	}

	for (int r = 0; r < size; ++r) {
		for (int c = 0; c < size; ++c) {
			printf("%d ", res[r][c]);
		}
		printf("\n");
	}

	return 0;
}

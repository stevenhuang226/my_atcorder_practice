#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int size;
	scanf("%" SCNd32, &size);

	int8_t **grid = malloc(size * sizeof(int8_t *));
	int8_t *grid_flat = malloc(size * size * sizeof(int8_t));

	for (int i = 0; i < size; ++i) {
		grid[i] = grid_flat + i * size;
	}

	for (int i = 0; i < size; ++i) {
		for (int i2 = 0; i2 < size; ++i2) {
			int c;
			c = getchar();

			if (c >= '0' && c <= '9') {
				grid[i][i2] = c - '0';
			} else if (c == '?') {
				grid[i][i2] = -1;
			} else {
				--i2;
			}
		}
	}

	int lim = size * 2 - 1;
	int8_t *res = malloc(lim * sizeof(int8_t));
	for (int i = 0; i < lim; ++i) {
		res[i] = -1;
	}

	for (int r = 0; r < size; ++r) {
		for (int c = 0; c < size; ++c) {
			int8_t num = grid[r][c];
			if (num == -1) {
				continue;
			}

			if (res[c + r] == -1) {
				res[c + r] = num;
				continue;
			}
			if (res[c + r] != num) {
				printf("-1\n");
				goto _end;
			}
		}
	}

	for (int i = 0; i < lim; ++i) {
		if (res[i] == -1) {
			res[i] = 1;
		}
	}

	for (int r = 0; r < size; ++r) {
		for (int c = 0; c < size; ++c) {
			printf("%d", res[r+c]);
		}
		printf("\n");
	}
_end:
	free(res);
	free(grid_flat);
	free(grid);
	return 0;
}

/*
 *
 * 101
 *  010
 *   101
 *
 * size: 2N - 1 == 2*3 - 1 == 5
 */

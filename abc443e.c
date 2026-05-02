#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int dr[] = {-1, -1, -1};
int dc[] = {-1, 0, 1};
int d_size = 3;

typedef struct {
	int r;
	int c;
} Node;

Node *queue;

int8_t **grid;

/*
 * grid =>
 * -1 visited
 *  0 empty
 *  1 well
 */

#define VISITED	0b0100
#define EMPTY	0b0001
#define WELL	0b0010

#define CLEAN	0b1000

void solve()
{
	int size, coli;
	scanf("%" SCNd32 " %" SCNd32, &size, &coli);

	for (int r = 0; r < size; ++r) {
		for (int c = 0; c < size; ++c) {
			int bfr;
			bfr = getchar();
			if (bfr == '.') {
				grid[r][c] = EMPTY;
			} else if (bfr == '#') {
				grid[r][c] = WELL;
			} else {
				--c;
			}
		}
	}

	for (int c = 0; c < size; ++c) {
		for (int r = size - 1; r >= 0; --r) {
			if (grid[r][c] & WELL) {
				break;
			}
			grid[r][c] |= CLEAN;
		}
	}

	int front = 0;
	int back = 0;

	queue[front].r = size - 1;
	queue[front].c = coli - 1;
	++front;

	grid[size-1][coli-1] |= VISITED;

	while (back < front) {
		int r = queue[back].r;
		int c = queue[back].c;
		++back;

		for (int k = 0; k < d_size; ++k) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (nr < 0 || nr >= size) {
				continue;
			}
			if (nc < 0 || nc >= size) {
				continue;
			}

			if (grid[nr+1][nc] & CLEAN) {
				for (int r = nr; r >= 0; --r) {
					grid[r][nc] &= ~(CLEAN);
					grid[r][nc] &= ~(WELL);
					grid[r][nc] |= EMPTY;
				}
			}

			if (grid[nr][nc] & VISITED) {
				continue;
			}
			if (grid[nr][nc] & WELL) {
				continue;
			}

			queue[front].r = nr;
			queue[front].c = nc;
			++front;

			grid[nr][nc] |= VISITED;
		}
	}

	for (int i = 0; i < size; ++i) {
		if (grid[0][i] & VISITED) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

int main()
{
	int exp_size = 3e3 + 8;

	grid = malloc(exp_size * sizeof(int8_t *));
	int8_t *grid_flat = malloc(exp_size * exp_size * sizeof(int8_t));
	for (int i = 0; i < exp_size; ++i) {
		grid[i] = grid_flat + i * exp_size;
	}

	queue = malloc(exp_size * exp_size * sizeof(Node));

	int times;
	scanf("%" SCNd32, &times);

	while (times--) solve();

	free(grid_flat);
	free(grid);
	free(queue);

	return 0;
}

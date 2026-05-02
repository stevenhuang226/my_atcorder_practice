#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
	int64_t value;
	int id;
} Ball;

Ball *balls;

int cmp(const void *l, const void *r)
{
	int64_t lv = (*(Ball *)l).value;
	int64_t rv = (*(Ball *)r).value;

	if (lv > rv) {
		return 1;
	} else if (lv < rv) {
		return -1;
	} else {
		return 0;
	}
}

void solve()
{
	int query_size;
	scanf("%d", &query_size);

	int hide[query_size];

	for (int i = 0; i < query_size; ++i) {
		int bfr;
		scanf("%d", &bfr);
		hide[i] = bfr - 1;
	}

	for (int i = 0; i <= query_size; ++i) {
		int trg_id = balls[i].id;

		int8_t brk = false;
		for (int i2 = 0; i2 < query_size; ++i2) {
			if (trg_id == hide[i2]) {
				brk = true;
				break;
			}
		}

		if (brk) {
			continue;
		}

		printf("%" PRId64 "\n", balls[i].value);
		return;
	}
}

int main()
{
	int size, queries;

	scanf("%d %d", &size, &queries);

	balls = malloc(size * sizeof(Ball));

	for (int i = 0; i < size; ++i) {
		int64_t bfr;
		scanf("%" SCNd64 , &bfr);

		balls[i].value = bfr;
		balls[i].id = i;
	}

	qsort(balls, size, sizeof(Ball), cmp);

	while (queries--) {
		solve();
	}

	free(balls);

	return 0;
}

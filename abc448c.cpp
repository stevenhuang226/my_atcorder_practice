#include <bits/stdc++.h>

using namespace std;

int exp_max = 3e5 + 8;

typedef struct Ball {
	int64_t value;
	int id;
};

Ball *balls;

int cmp(const void *l, const void *r)
{
	int64_t vl = (*(Ball **)l)->value;
	int64_t vr = (*(Ball **)r)->value;

	if (vl > vr) {
		return 1;
	} else if (vl < vr) {
		return -1;
	} else {
		return 0;
	}
}

void solve()
{
	int size;
	cin >> size;

	int hide[size];

	for (int i = 0; i < size; ++i) {
		int bfr = 0;
		scanf("%" SCNd32, &bfr);
		hide[i] = bfr;
	}

	for (int i = 0;;) {
		int trg_id = balls[i].id;

		int8_t brk = false;
		for (int i2 = 0; i2 < size; ++i2) {
			if (trg_id == hide[i2]) {
				brk = true;
				break;
			}
		}

		if (brk) {
			continue;
		}

		printf("%" PRId64 "\n", balls[i].value);
	}
}
 
int main()
{
	int times, size;

	cin >> size >> times;

	balls = (Ball *)malloc(size * sizeof(int64_t));

	for (int i = 0; i < size; ++i) {
		int64_t bfr;

		balls[i].value = bfr;
		balls[i].id = i;
	}

	qsort(balls, size, sizeof(Ball), cmp);

	for (int i = 0; i < times; ++i) {
		solve();
	}

	free(balls);

	return 0;
}

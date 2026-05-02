#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int64_t ages, beans;

	scanf("%" SCNd64 " %" SCNd64, &ages, &beans);

	/* (ages + ages + n) * n+1 >= beans * 2 */

	int64_t left = 0;
	int64_t right = beans;

	int64_t trg = beans * 2;

	while (left < right) {
		int64_t mid = (left + right) / 2;

		int64_t eat = (ages + ages + mid) * (mid + 1);

		if (eat < trg) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	printf("%" PRId64 "\n", left);

	return 0;
}

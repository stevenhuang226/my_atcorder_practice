#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t *nums;

void solve()
{
	int size;
	scanf("%" SCNd32, &size);

	for (int i = 0; i < size; ++i) {
		int64_t bfr;
		scanf("%" SCNd64, &bfr);
		nums[i] = bfr;
	}

	int64_t operations = 0;

	for (int i = 0; i < size - 1; ++i) {
		if (nums[i+1] > nums[i] + 1) {
			operations += nums[i+1] - (nums[i] + 1);
			nums[i+1] = nums[i] + 1;
		}
	}
	for (int i = size - 1; i > 0; --i) {
		if (nums[i-1] > nums[i] + 1) {
			operations += nums[i-1] - (nums[i] + 1);
			nums[i-1] = nums[i] + 1;
		}
	}

	printf("%" PRId64 "\n", operations);
}

int main()
{
	int exp_size = 3e5 + 10;
	nums = malloc(exp_size * sizeof(int64_t));

	int times;
	scanf("%" SCNd32, &times);

	while (times--) {
		solve();
	}

	free(nums);

	return 0;
}

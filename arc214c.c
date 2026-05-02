/*
 * auth: stevenhuang.dog@gmail.com
 * Help: ChatGPT, official solution
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MOD 998244353
#define EXP_SIZE (1e5 + 8)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int *strengths;
int *dp;

int main()
{
	int size;
	scanf("%" SCNd32, &size);

	strengths = malloc(size * sizeof(int));
	dp = calloc(EXP_SIZE, sizeof(int));

	int64_t total_sum = 0;

	for (int i = 0; i < size; ++i) {
		int bfr;
		scanf("%" SCNd32, &bfr);
		strengths[i] = bfr;
		total_sum += (int64_t)bfr;
	}

	if (total_sum % 2 == 1) {
		printf("0\n");
		goto _end;
	}

	int trg_sum = total_sum / 2;
	dp[0] = 1;
	for (int i = 0; i < size; ++i) {
		int strength = strengths[i];
		for (int sum = trg_sum; sum >= strength; --sum) {
			dp[sum] = (dp[sum] + dp[sum - strength]) % MOD;
		}
	}

	int64_t half_subsets = dp[trg_sum];
	int64_t ans = ((half_subsets * half_subsets) - (2 * half_subsets)) % MOD;

	printf("%" PRId64 "\n", ans);
_end:
	free(strengths);
	free(dp);
	return 0;
}

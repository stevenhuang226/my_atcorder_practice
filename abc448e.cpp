/*
 * auth: stevenhuang.dog@gmail.com
 * with ChatGPT help
 */

#include <bits/stdc++.h>
using namespace std;

/*
 * 10007 == 1e4 + 7
 *
 * [N/M] % 1e4+7
 *
 * N = Mq + t				(0 <= t < M)
 * q = (1e4+7) * k + s			(0 <= s < 1e4+7)
 * N = M((1e4+7)*k+s)  + t
 * N = M(1e4+7)*k + M*s + t
 *
 * N % ((1e4+7)*M) = M*s + t
 * (N % ((1e4+7)*M)) / M = s + t/M 	(0 <= t/M < 1)
 * look at 's' that what we want, so answer is (N % (1e4+7) * M) / M
 */
 


int64_t bit_pow(int64_t base, int64_t e, int64_t mod)
{
	int64_t res = 1 % mod;

	while (e > 0) {
		if (e & 1) {
			res = (res * base) % mod;
		}

		base = (base * base) % mod;

		e >>= 1;
	}

	return res;
}

int64_t repeat(int64_t times, int64_t base, int64_t mod)
{
	if (times == 1 || base == 0) {
		return base;
	}

	if (times % 2 == 0) {
		int64_t blk = repeat(times/2, base, mod);
		int64_t res = (blk * bit_pow(10, times/2, mod)) % mod;
		res = (res + blk) % mod;
		return res;
	}

	int64_t res = repeat(times-1, base, mod);
	res = (res * 10) % mod;
	res = (res + base) % mod;
	return res;
}

int main()
{
	int64_t init_mod = 1e4 + 7;
	int64_t nums, div_num;

	cin >> nums >> div_num;

	int64_t mod = div_num * init_mod;

	int64_t ans = 0;
	for (int i = 0; i < nums; ++i) {
		int64_t c, l;
		scanf("%" SCNd64 " %" SCNd64, &c, &l);

		ans = (ans * bit_pow(10, l, mod) + repeat(l, c, mod)) % mod;
	}

	int64_t answer = ans / div_num;

	printf("%d\n", answer);

	return 0;
}

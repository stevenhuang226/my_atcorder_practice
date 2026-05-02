/*
 * auth: stevenhuang.dog@gmail.com
 * With ChatGPT help
 */

#include <bits/stdc++.h>

#define MOD 1e9 + 7;
int64_t mod = MOD;

int64_t pow(int64_t base, int64_t e)
{
	int64_t res = 1;
	while (e) {
		if (e & 1) {
			res = res * base % mod;
		}
		base = base * base % mod;
		e >>= 1;
	}

	return res;
}

int64_t *factorial;
int64_t *inv_factorial;

void init_build(int64_t size)
{
	factorial[0] = 1;
	for (int64_t i = 1; i < size; ++i) {
		factorial[i] = (factorial[i-1] * i) % mod;
	}

	inv_factorial[size-1] = pow(factorial[size-1], mod - 2);
	for (int64_t i = size - 1; i >= 1; --i) {
		inv_factorial[i-1] = (inv_factorial[i] * i) % mod;
	}
}

int64_t comb(int64_t n, int64_t k)
{
	if (k < 0 || k > n) {
		return 0;
	}

	return (factorial[n] * ((inv_factorial[k] * inv_factorial[n-k]) % mod)) % mod;
}

int main()
{
	int64_t size, lim;
	std::cin >> size >> lim;

	int64_t exp_max = size + lim + 8;

	factorial = (int64_t *)malloc(exp_max * sizeof(int64_t));
	inv_factorial = (int64_t *)malloc(exp_max * sizeof(int64_t));
	init_build(exp_max);

	int64_t odd = (size + 2) / 2;
	int64_t even = (size + 1) / 2;

	int64_t pa = (comb(odd + lim - 1, odd - 1) * comb(even + lim, even)) % mod;
	int64_t pb = (comb(odd + lim, odd) * comb(even + lim - 1, even - 1)) % mod;
	int64_t pc = (comb(odd + lim - 1, odd - 1) * comb(even + lim - 1, even - 1)) % mod;

	int64_t res = ((pa + pb) % mod) - pc;
	if (res < 0) {
		res += mod;
	}

	printf("%" PRId64 "\n", res);

	free(factorial);
	free(inv_factorial);
	return 0;
}

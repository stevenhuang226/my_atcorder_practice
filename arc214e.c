/*
 * auth: stevenhuang.dog@gmail.com
 * with chatgpt, official_solution help
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int exp_size = 3e5 + 8;

int *source;

int *adj_head;
int *adj_next;

int *permutation;

int *tree;
int tree_size;

void init(int size)
{
	memset(tree, 0x00, (size + 2) * sizeof(int));
	tree_size = size + 2;
}

void fenwick_update(int index, const int delta)
{
	while (index < tree_size) {
		tree[index] += delta;
		index += index & (-index);
	}
}

int fenwick_query(int index)
{
	int sum = 0;
	while (index > 0) {
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

void build_permutation(int size)
{
	for (int i = size-1; i >= 0; --i) {
		int value = source[i];
		int trg_idx = adj_head[value];
		permutation[i] = trg_idx;
		adj_head[value] = adj_next[trg_idx];
	}
}

int64_t count_inversion(int size)
{
	int64_t count = 0;
	for (int i = 0; i < size; ++i) {
		int value = permutation[i] + 1;
		int less_equal = fenwick_query(value);
		count += i - less_equal;
		fenwick_update(value, 1);
	}

	return count;
}

void solve()
{
	int size;
	int64_t k;
	scanf("%" SCNd32 " %" SCNd64, &size, &k);

	init(size);

	for (int i = 0; i < size; ++i) {
		int value;
		scanf("%" SCNd32, &value);
		source[i] = value;
	}

	for (int i = 0; i < size; ++i) {
		int value;
		scanf("%" SCNd32, &value);

		adj_next[i] = adj_head[value];
		adj_head[value] = i;
	}

	build_permutation(size);
	int64_t inv = count_inversion(size);

	int64_t min_cost = (inv + k - 1) / k;

	int64_t res;
	if (k % 2 == 0) {
		if (inv % 2 == 0) {
			res = min_cost;
		} else {
			res = -1;
		}
	} else {
		if ((min_cost % 2) != (inv % 2)) {
			res = min_cost + 1;
		} else {
			res = min_cost;
		}
	}

	printf("%" PRId64 "\n", res);
}

int main()
{
	source = malloc(exp_size * sizeof(int));
	adj_head = malloc(exp_size * sizeof(int));
	adj_next = malloc(exp_size * 2 * sizeof(int));
	permutation = malloc(exp_size * sizeof(int));
	tree = malloc(exp_size * sizeof(int));

	int times;
	scanf("%" SCNd32, &times);

	while (times--) {
		solve();
	}

	free(source);
	free(adj_head);
	free(adj_next);
	free(permutation);
	free(tree);

	return 0;
}

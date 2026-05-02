#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct {
	int freq;
	int value;
} Freq;

typedef struct {
	int64_t target;
	int id;
} Query;

typedef struct {
	int *tree;
	int32_t size;
} Fenwick;

int cmpFreq_freq(const void *l, const void *r)
{
	int left_freq = (*(Freq *)l).freq;
	int right_freq = (*(Freq *)r).freq;

	if (left_freq != right_freq) {
		return left_freq - right_freq;
	} else {
		return (*(Freq *)l).value - (*(Freq *)r).value;
	}
}

int cmpQuery(const void *l, const void *r)
{
	int64_t left_target = (*(Query *)l).target;
	int64_t right_target = (*(Query *)r).target;

	if (left_target > right_target) {
		return 1;
	} else if (left_target < right_target) {
		return -1;
	} else {
		return 0;
	}
}

Fenwick *fw_create(int32_t size)
{
	Fenwick *fenwick = malloc(sizeof(Fenwick));
	fenwick->tree = calloc((size+1), sizeof(int));
	fenwick->size = size;
	return fenwick;
}

void fw_insert(Fenwick *fenwick, int index, int delta)
{
	while (index <= fenwick->size) {
		fenwick->tree[index] += delta;
		index += index & -index;
	}
}

int fw_query(Fenwick *fenwick, int index)
{
	int result = 0;
	while (index) {
		result += fenwick->tree[index];
		index -= index & -index;
	}
	return result;
}

int fw_kth(Fenwick *fenwick, int target)
{
	int32_t index = 0;

	int step = 1;
	while (step <= fenwick->size) {
		step <<= 1;
	}
	step >>= 1;

	for (; step > 0; step >>= 1) {
		int next = index + step;
		if (next <= fenwick->size && fenwick->tree[next] < target) {
			target -= fenwick->tree[next];
			index = next;
		}
	}

	return index + 1;
}

void fw_clean(Fenwick *fenwick)
{
	free(fenwick->tree);
	free(fenwick);
}

int main()
{
	int init_size, limit;
	scanf("%d %d", &init_size, &limit);

	int *init_input = malloc(init_size * sizeof(int));
	Freq *frequency = malloc(limit * sizeof(Freq));
	for (int i = 0; i < limit; ++i) {
		frequency[i].freq = 0;
		frequency[i].value = i + 1;
	}

	for (int i = 0; i < init_size; ++i) {
		int bfr;
		scanf("%" SCNd32, &bfr);

		++frequency[bfr-1].freq;
		init_input[i] = bfr;
	}

	int queries_num;
	scanf("%" SCNd32, &queries_num);

	Query *queries = malloc(queries_num * sizeof(Query));
	int *result = malloc(queries_num * sizeof(int));

	for (int i = 0; i < queries_num; ++i) {
		int64_t bfr;
		scanf("%" SCNd64, &bfr);

		queries[i].target = bfr - 1;
		queries[i].id = i;
	}

	qsort(queries, queries_num, sizeof(Query), cmpQuery);

	int queries_ptr = 0;
	while (queries_ptr < queries_num && queries[queries_ptr].target < init_size) {
		int64_t target = queries[queries_ptr].target;
		int id = queries[queries_ptr].id;
		result[id] = init_input[target];

		++queries_ptr;
	}

	qsort(frequency, limit, sizeof(Freq), cmpFreq_freq);

	Fenwick *fw_tree = fw_create(limit+1);

	int64_t section_start = 0;
	int64_t section_end = init_size;
	int loop = 0;
	while (queries_ptr < queries_num) {
		section_start = section_end;

		/* extend group */
		fw_insert(fw_tree, frequency[loop].value, 1);
		while (loop+1 < limit && frequency[loop].freq == frequency[loop+1].freq) {
			++loop;
			fw_insert(fw_tree, frequency[loop].value, 1);
		}
		++loop; /* make loop == loop_length */

		/* compute repeat time */
		if (loop < limit) { /* still have next group, not infinty */
			int64_t repeat = frequency[loop].freq - frequency[loop-1].freq;
			section_end = section_start + (loop * repeat);
		} else { /* doesn't have next gruop, infinty */
			section_end = INT64_MAX;
		}

		/* fill in result */
		while (queries_ptr < queries_num && queries[queries_ptr].target < section_end) {
			int64_t target = queries[queries_ptr].target;
			int id = queries[queries_ptr].id;
			int index = (int64_t)(target-section_start) % (int64_t)(loop);
			result[id] = fw_kth(fw_tree, (index+1));

			++queries_ptr;
		}
	}
_output:
	for (int i = 0; i < queries_num; ++i) {
		printf("%d\n", result[i]);
	}
	fw_clean(fw_tree);
	free(init_input);
	free(result);
	free(frequency);
	free(queries);

	return 0;
}

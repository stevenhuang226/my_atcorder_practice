#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
typedef struct {
	int64_t gap;
	int64_t left;
	int64_t right;
} GapNode;

GapNode *gap_nodes;

int cmp_gap_node(const void *l, const void *r)
{
	int64_t l_gap = (*(GapNode *)l).gap;
	int64_t r_gap = (*(GapNode *)r).gap;

	if (l_gap > r_gap) {
		return -1;
	} else if (l_gap < r_gap) {
		return 1;
	} else {
		return 0;
	}
}

void solve()
{
	int64_t zombie_count, bait_count, road_lim;

	scanf("%"SCNd64" %"SCNd64" %"SCNd64, &zombie_count, &bait_count, &road_lim);

	int64_t zombie_most_left = road_lim;
	int64_t zombie_most_right = 0;
	int64_t gap_node_count = zombie_count - 1;

	int64_t last_position;
	scanf("%"SCNd64, &last_position);
	zombie_most_left = zombie_most_right = last_position;
	for (int i = 1; i < zombie_count; ++i) {
		int64_t position;
		scanf("%"SCNd64, &position);

		gap_nodes[i].gap = position - last_position;
		gap_nodes[i].left = last_position;
		gap_nodes[i].right = position;
	}

	qsort(gap_nodes, gap_node_count, sizeof(GapNode), cmp_gap_node);

	int64_t gap_prefix = 0;

	for (int i = 0; i < gap_node_count; ++i) {
		int64_t total_time = 0;
		total_time += gap_prefix / 2;
	}
}

int main()
{
	int32_t times;
	scanf("%" SCNd32, &times);

	while (times--) {
		solve();
	}

	return 0;
}

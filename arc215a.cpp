#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int64_t zombie_count, bait_count, road_limit;
	cin >> zombie_count >> bait_count >> road_limit;

	vector<int64_t> position(zombie_count);
	for (int i = 0; i < zombie_count; ++i) {
		scanf("%" SCNd64, &(position[i]));
	}
	sort(position.begin(), position.end());

	int64_t short_side = min(position[0], road_limit - position[zombie_count-1]);
	int64_t long_side = max(position[0], road_limit - position[zombie_count-1]);

	vector<int64_t> gaps(zombie_count - 1);
	for (int i = 0; i < zombie_count - 1; ++i) {
		gaps[i] = position[i+1] - position[i];
	}

	sort(gaps.begin(), gaps.end(), greater<int64_t>());

	int64_t best_ans = 0;

	int64_t used_gaps_distance = 0;
	for (int used = 0; used < zombie_count && used <= bait_count; ++used) {
		int64_t survive_time = 0;
		int64_t half_used_dis = used_gaps_distance / 2;

		survive_time += half_used_dis;

		int64_t remained = bait_count - used;
		if (remained > 0) {
			survive_time += long_side + half_used_dis;
			--remained;
		}
		if (remained > 0) {
			int64_t shift = short_side + long_side + used_gaps_distance;
			survive_time += shift * remained;
		}

		best_ans = max(best_ans, survive_time);

		if (used < zombie_count - 1) {
			used_gaps_distance += gaps[used];
		}
	}

	printf("%" PRId64 "\n", best_ans);
}

int main()
{
	int times;
	cin >> times;

	while (times--) {
		solve();
	}

	return 0;
}

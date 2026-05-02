#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int64_t limit;
	cin >> limit;

	vector<int> divider_pos;
	vector<bool> group_odd(limit + 1, false);
	vector<bool> group_even(limit + 1, false);
	bool is_odd = true;

	for (int i = 0; i < limit * 2; ++i) {
		int num;
		scanf("%" SCNd32, &num);

		if (is_odd && group_odd[num]) {
			is_odd = false;
			divider_pos.push_back(i);
		} else if (! is_odd && group_even[num]) {
			is_odd = true;
			divider_pos.push_back(i);
		}

		if (is_odd) {
			group_odd[num] = true;
		} else {
			group_even[num] = true;
		}
	}

	int64_t divider_pos_size = divider_pos.size();
	printf("%" PRId64 "\n", divider_pos_size);

	for (int i = 0; i < divider_pos_size; ++i) {
		printf("%" PRId64 " ", divider_pos[i]);
	}
	printf("\n");
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

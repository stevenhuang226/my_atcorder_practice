#include <bits/stdc++.h>

/*
 * I give up...
 */

using namespace std;

int exp_max = 1e5 + 8;

int main()
{
	int size;
	cin >> size;

	vector<vector<int64_t>> weightToNums(exp_max, vector<int64_t>(2, 0));

	for (int i = 0; i < size; ++i) {
		int weight;
		int64_t nums;

		scanf("%" SCNd32 " %" SCNd64, &weight, &nums);

		if (nums > weightToNums[weight][0]) {
			weightToNums[weight][1] = weightToNums[weight][0];
			weightToNums[weight][0] = nums;
		} else if (nums > weightToNums[weight][1]) {
			weightToNums[weight][1] = nums;
		}
	}
}



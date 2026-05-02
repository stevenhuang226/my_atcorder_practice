#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int a;
	int b;
	int c;
} NumNode;

void solve()
{
	int size;
	scanf("%d", &size);

	vector<NumNode> nums(size);
	for (int i = 0; i < size; ++i) {
		scanf("%d %d %d", &(nums[i].a), &(nums[i].b), &(nums[i].c));
	}

	sort(nums.begin(), nums.end(),
			[](const NumNode &left, const NumNode &right)
			{
				if (left.a != right.a)
					return left.a > right.a;
				if (left.b != right.b)
					return left.b > right.b;

				return left.c > right.c;
			});

	vector<int> suffix_max_b(size+1, 0);
	vector<int> suffix_max_c(size+1, 0);
	for (int i = size - 1; i >= 0; --i) {
		suffix_max_b[i] = max(suffix_max_b[i+1], nums[i].b);
		suffix_max_c[i] = max(suffix_max_c[i+1], nums[i].c);
	}

	int prefix_min_b = INT32_MAX;
	int prefix_min_c = INT32_MAX;

	for (int i = 0; i < size - 1; ++i) {
		prefix_min_b = min(prefix_min_b, nums[i].b);
		prefix_min_c = min(prefix_min_c, nums[i].c);

		if (nums[i].a > nums[i+1].a &&
				prefix_min_b > suffix_max_b[i+1] &&
				prefix_min_c > suffix_max_c[i+1]) {
			printf("%d\n", i+1);
			return;
		}
	}
	printf("%d\n", size);
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

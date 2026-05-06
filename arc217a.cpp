#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int num;
	scanf("%d", &num);

	vector<int> res(num);
	for (int i = 0; i < num; ++i) {
		res[i] = i+1;
	}

	for (int i = 2; i < num; i += 4) {
		swap(res[i-1], res[i]);
	}

	for (int i = 0; i < num; ++i) {
		printf("%d ", res[i]);
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

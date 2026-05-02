#include <bits/stdc++.h>
using namespace std;

int max_len;

int dfs(vector<vector<int>> &tree, int curr_id, int parent_id)
{
	int degree = tree[curr_id].size();

	int max_sub_len = 0;
	int sec_sub_len = 0;

	for (int i = 0; i < degree; ++i) {
		int child_id = tree[curr_id][i];

		if (child_id == parent_id) {
			continue;
		}

		int child_len = dfs(tree, child_id, curr_id);

		if (child_len > max_sub_len) {
			sec_sub_len = max_sub_len;
			max_sub_len = child_len;
		} else if (child_len > sec_sub_len) {
			sec_sub_len = child_len;
		}
	}

	if (degree >= 3) {
		max_len = max(max_len, max_sub_len + 1);
	}
	if (degree >= 4) {
		max_len = max(max_len, max_sub_len + sec_sub_len + 1);
	}

	if (degree < 3) {
		return 0;
	}
	if (degree < 4) {
		return 1;
	}
	return max_sub_len + 1;
}

void solve()
{
	int vertices;
	cin >> vertices;

	vector<vector<int>> tree(vertices+1, vector<int>());
	max_len = 1;

	for (int i = 0; i < vertices - 1; ++i) {
		int node_u, node_v;
		scanf("%" SCNd32 " %" SCNd32, &node_u, &node_v);

		tree[node_u].push_back(node_v);
		tree[node_v].push_back(node_u);
	}

	dfs(tree, 1, 0);

	cout << max_len << "\n";
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

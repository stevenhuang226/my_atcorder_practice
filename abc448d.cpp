#include <bits/stdc++.h>

using namespace std;


vector<int> adj_to;
vector<int> adj_next;
vector<int> adj_head;
int edge_count;

vector<int64_t> weight;
unordered_map<int64_t, int> path_freq;

vector<int8_t> result;

void create_edge(int from, int to)
{
	adj_to[edge_count] = to;
	adj_next[edge_count] = adj_head[from];
	adj_head[from] = edge_count;
	++edge_count;
}

void dfs(int curr_id, int parent_id, int8_t repeated)
{
	int64_t curr_weight = weight[curr_id];
	if (++path_freq[curr_weight] >= 2) {
		repeated = true;
	}

	if (repeated) {
		result[curr_id] = true;
	}

	int next_edge = adj_head[curr_id];
	while (next_edge >= 0) {
		int child_id = adj_to[next_edge];
		next_edge = adj_next[next_edge];

		if (child_id == parent_id) continue;
		dfs(child_id, curr_id, repeated);
	}

	--path_freq[curr_weight];
}

int main()
{
	int vertices;

	cin >> vertices;

	weight.resize(vertices+1);
	adj_to.resize((vertices+1) * 2);
	adj_next.resize((vertices+1) * 2);
	adj_head.resize((vertices+1), -1);
	result.resize(vertices+1);
	edge_count = 0;

	for (int i = 1; i <= vertices; ++i) {
		int64_t bfr;
		scanf("%" SCNd64, &bfr);
		weight[i] = bfr;
	}

	for (int i = 0; i < vertices - 1; ++i) {
		int node_u, node_v;
		scanf("%" SCNd32 " %" SCNd32, &node_u, &node_v);
		create_edge(node_u, node_v);
		create_edge(node_v, node_u);
	}

	dfs(1, -1, false);

	for (int i = 1; i <= vertices; ++i) {
		if (result[i] == true) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}

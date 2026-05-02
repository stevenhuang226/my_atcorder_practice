#include <bits/stdc++.h>

#define MOD 998244353

int64_t mod = MOD;

std::vector<int> root;

int un_find(int target)
{
	if (root[target] == target) {
		return target;
	}

	root[target] = un_find(root[target]);

	return root[target];
}

void un_merge(int root_left, int root_right)
{
	if (root_left == root_right) {
		return;
	}

	root[root_left] = un_find(root_right);
}

void un_init(int size)
{
	root.resize(size);

	for (int i = 0; i < size; ++i) {
		root[i] = i;
	}
}

int main()
{
	int vertices, edges;
	std::cin >> vertices >> edges;

	un_init(vertices + 1);

	int components = vertices;

	std::vector<int> nodes_u(edges);
	std::vector<int> nodes_v(edges);
	std::vector<int> weights(edges);

	int64_t weight = 1;
	for (int i = 0; i < edges; ++i) {
		int node_u, node_v;
		scanf("%" SCNd32 " %" SCNd32, &node_u, &node_v);
		weight = (weight * 2) % mod;

		nodes_u[i] = node_u;
		nodes_v[i] = node_v;
		weights[i] = weight;
	}

	int64_t deleted_weight = 0;

	for (int i = edges - 1; i >= 0; --i) {
		int node_u = nodes_u[i];
		int node_v = nodes_v[i];
		int weight = weights[i];

		int root_u = un_find(node_u);
		int root_v = un_find(node_v);

		if (root_u == root_v) continue;

		if (components <= 2) {
			deleted_weight = (deleted_weight + weight) % mod;
			continue;
		}

		un_merge(root_u, root_v);
		--components;
	}

	std::cout << deleted_weight << "\n";

	return 0;
}

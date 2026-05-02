#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define DEF_XOR_VAL 0

int *adj_to;
int *adj_next;
int *adj_head;
int *adj_xor;
int edge_count;

int *card;

int *queue;

void init(int size)
{
	for (int i = 0; i < size; ++i) {
		adj_head[i] = -1;
		card[i] = -1;
	}
	edge_count = 0;
}

void create_edge(int node_u, int node_v, int xor_val)
{
	adj_to[edge_count] = node_v;
	adj_xor[edge_count] = xor_val;
	adj_next[edge_count] = adj_head[node_u];
	adj_head[node_u] = edge_count;
	++edge_count;
}

void solve()
{
	int vertices, edges;
	scanf("%" SCNd32 " %" SCNd32, &vertices, &edges);

	init(vertices + 1);

	for (int i = 0; i < edges; ++i) {
		int node_u, node_v, xor_value;
		scanf("%d %d %d", &node_u, &node_v, &xor_value);
		create_edge(node_u, node_v, xor_value);
		create_edge(node_v, node_u, xor_value);
	}

	if (vertices % 2 == 1) {
		printf("-1\n");
		return;
	}

	int front, back;
	front = back = 0;

	card[1] = DEF_XOR_VAL; // 0
	queue[front++] = 1;

	while (back < front) {
		int from = queue[back++];
		int next_edge = adj_head[from];
		while (next_edge >= 0) {
			int to = adj_to[next_edge];
			int xor_value = adj_xor[next_edge];
			next_edge = adj_next[next_edge];

			if (card[to] >= 0) {
				continue;
			}

			card[to] = xor_value ^ card[from];
			queue[front++] = to;
		}
	}

	int vector_xor = 0;
	for (int i = 1; i <= vertices; ++i) {
		vector_xor ^= card[i];
	}

	int all_card_xor = 0;
	for (int i = 1; i <= vertices; ++i) {
		all_card_xor ^= i;
	}

	printf("%d\n", all_card_xor ^ vector_xor);
}

int main()
{
	int exp_size = 2e5 + 8;
	adj_to = malloc(exp_size * 2 * sizeof(int));
	adj_next = malloc(exp_size * 2 * sizeof(int));
	adj_head = malloc(exp_size * sizeof(int));
	adj_xor = malloc(exp_size * 2 * sizeof(int));
	card = malloc(exp_size * sizeof(int));
	queue = malloc(exp_size * sizeof(int));

	int times;
	scanf("%" SCNd32, &times);

	while (times--) {
		solve();
	}

	free(adj_to);
	free(adj_next);
	free(adj_head);
	free(adj_xor);
	free(card);
	free(queue);

	return 0;
}

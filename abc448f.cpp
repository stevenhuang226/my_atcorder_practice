#include <bits/stdc++.h>

using namespace std;

int64_t exp_max = 6e4 + 8;
int64_t max_axis = 2e7 + 9;
int64_t max_time = 1e10 - 1;

typedef struct {
	int64_t x;
	int64_t y;
	int64_t id;
} Node;


int main()
{
	int size;

	cin >> size;
	vector<Node> nodes(size);

	for (int i = 0; i < size; ++i) {
		int64_t x,y;
		scanf("%d %d", &x, &y);

		nodes[i].x = x;
		nodes[i].y = y;
		nodes[i].id = i + 1;
	}
}

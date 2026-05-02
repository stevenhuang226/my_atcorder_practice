#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

enum TYPE {
	ROW = 1,
	COL = 2
};

int main()
{
	int64_t rows, cols, queries;
	scanf("%" SCNd64 " %" SCNd64 " %" SCNd64, &rows, &cols, &queries);

	for (int i = 0; i < queries; ++i) {
		int32_t type, nums;
		scanf("%d %d", &type, &nums);

		if (type == ROW) {
			printf("%d\n", nums * cols);
			rows -= nums;
		} else if (type == COL) {
			printf("%d\n", nums * rows);
			cols -= nums;
		}
	}

	return 0;
}

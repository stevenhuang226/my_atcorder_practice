#include <stdio.h>
#include <stdlib.h>

int main()
{
	int exp_max = 1e6 + 8;

	int *pos_a = malloc(exp_max * sizeof(int));
	int *pos_b = malloc(exp_max * sizeof(int));
	int *pos_c = malloc(exp_max * sizeof(int));
	int a_count = 0;
	int b_count = 0;
	int c_count = 0;

	int count = 0;
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n') {
		switch (ch) {
			case 'A':
				pos_a[a_count++] = count++;
				break;
			case 'B':
				pos_b[b_count++] = count++;
				break;
			case 'C':
				pos_c[c_count++] = count++;
				break;
		}
	}

	int use_a = 0;
	int use_b = 0;
	int use_c = 0;

	int res_count = 0;

	while (use_a < a_count && use_b < b_count && use_c < c_count) {
		if (pos_a[use_a] < pos_b[use_b] && pos_b[use_b] < pos_c[use_c]) {
			++use_a;
			++use_b;
			++use_c;
			++res_count;
		}

		if (pos_a[use_a] > pos_b[use_b]) {
			++use_b;
			continue;
		}

		if (pos_b[use_b] > pos_c[use_c]) {
			++use_c;
			continue;
		}
	}

	printf("%d\n", res_count);

	free(pos_a);
	free(pos_b);
	free(pos_c);

	return 0;
}

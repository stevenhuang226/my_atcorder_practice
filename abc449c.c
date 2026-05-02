#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int length, left, right;
	scanf("%d %d %d", &length, &left, &right);

	int **char_count = malloc(26 * sizeof(int *));
	int *char_count_flat = malloc(26 * (length+1) * sizeof(int));
	for (int i = 0; i < 26; ++i) {
		char_count[i] = char_count_flat + i * (length+1);
	}

	char *string = malloc((length+1) * sizeof(char));
	scanf("%s", string);

	for (int i = 0; i < 26; ++i) {
		char_count[i][0] = 0;
		for (int i2 = 0; i2 < length; ++i2) {
			int ch = string[i2] - 'a';

			char_count[i][i2+1] =
				char_count[i][i2] + (ch == i);
		}
	}

	int64_t pair_count = 0;
	for (int i = 0; i < length - left; ++i) {
		int ch = string[i] - 'a';

		int left_prefix, right_prefix;

		left_prefix = char_count[ch][i+left];
		if (i + right + 1 > length) {
			right_prefix = char_count[ch][length];
		} else {
			right_prefix = char_count[ch][i+right+1];
		}

		pair_count += (int64_t)(right_prefix - left_prefix);
	}

	printf("%" PRId64 "\n", pair_count);

	free(string);
	free(char_count_flat);
	free(char_count);

	return 0;
}

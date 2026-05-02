#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int main()
{
	int exp_max = 200;
	char *string = malloc(exp_max * sizeof(char));
	int count = 0;

	int freq[26] = {0};

	int c;
	while ((c = getchar()) != EOF && c != '\n') {
		string[count++] = c;
		++freq[c - 'a'];
	}

	int max_freq = 0;
	for (int i = 0; i < 26; ++i) {
		max_freq = MAX(max_freq, freq[i]);
	}

	char *ret = malloc(exp_max * sizeof(char));
	int rptr = 0;

	for (int i = 0; i < count; ++i) {
		c = string[i];
		if (freq[c - 'a'] == max_freq) {
			continue;
		}
		printf("%c", c);
	}
	printf("\n");

	free(string);

	return 0;
}

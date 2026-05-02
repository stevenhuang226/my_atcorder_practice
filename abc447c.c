#include <stdio.h>
#include <stdlib.h>

int main()
{
	int exp_max = 3e5 + 8;

	char *source = malloc(exp_max * sizeof(char));
	int s_count = 0;
	char *target = malloc(exp_max * sizeof(char));
	int t_count = 0;

	int c;
	while ((c = getchar()) != EOF && c != '\n') {
		source[s_count++] = c;
	}

	while ((c = getchar()) != EOF && c != '\n') {
		target[t_count++] = c;
	}

	int step = 0;
	int pt = 0;
	int ps = 0;
	while (pt < t_count) {
		if (target[pt] == source[ps]) {
			++pt;
			++ps;
			continue;
		}
		if (target[pt] == 'A' && source[ps] != 'A') {
			++step;
			++pt;
			continue;
		}
		if (source[ps] == 'A' && target[pt] != 'A') {
			++step;
			++ps;
			continue;
		}

		if (source[ps] != 'A' && target[pt] != 'A') {
			step = -1;
			break;
		}
	}
	while (ps < s_count) {
		if (source[ps] != 'A') {
			step = -1;
			break;
		}
		++ps;
		++step;
	}

	printf("%d\n", step);

	free(source);
	free(target);
	return 0;
}

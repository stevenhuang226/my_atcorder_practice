#include <stdio.h>

#define BFR_SIZE 20
int main()
{
	char bfr[BFR_SIZE];

	int ptr = 0;
	int c;
	while ((c = getchar()) != EOF && c != '\n') {
		bfr[ptr++] = (char)c;
	}
	bfr[ptr++] = 's';
	bfr[ptr++] = '\0';

	printf("%s\n", bfr);

	return 0;
}

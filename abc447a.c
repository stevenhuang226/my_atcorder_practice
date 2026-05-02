#include <stdio.h>

int main()
{
	int capacity, request;

	scanf("%d %d", &capacity, &request);

	if ((capacity + 1 >> 1) >= request) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

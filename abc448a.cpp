#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size, small;

	cin >> size >> small;

	for (int i = 0; i < size; ++i) {
		int bfr;
		scanf("%d", &bfr);

		if (bfr < small) {
			small = bfr;
			printf("1\n");
		} else {
			printf("0\n");
		}
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int dishes, peppers;
	cin >> dishes >> peppers;

	vector<int> typeOfPeppers(peppers + 1);

	for (int i = 0; i < peppers; ++i) {
		cin >> typeOfPeppers[i+1];
	}

	int added = 0;
	for (int i = 0; i < dishes; ++i) {
		int type, use;

		cin >> type >> use;

		if (typeOfPeppers[type] >= use) {
			added += use;
			typeOfPeppers[type] -= use;
		} else if (typeOfPeppers[type] > 0) {
			added += typeOfPeppers[type];
			typeOfPeppers[type] = 0;
		}
	}

	cout << added << "\n";

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Freq {
	int freq;
	int value;
};

struct Query {
	int64_t target;
	int id;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int init_size, limit;
	cin >> init_size >> limit;

	vector<int> init_input(init_size);
	vector<Freq> frequency(limit);

	for (int value = 0; value < limit; ++value) {
		frequency[value] = {0, value + 1};
	}

	for (int idx = 0; idx < init_size; ++idx) {
		int value;
		cin >> value;
		frequency[value - 1].freq++;
		init_input[idx] = value;
	}

	int queries_num;
	cin >> queries_num;

	vector<Query> queries(queries_num);
	vector<int> result(queries_num);

	for (int idx = 0; idx < queries_num; ++idx) {
		int64_t target;
		cin >> target;
		queries[idx] = {target - 1, idx};
	}

	sort(queries.begin(), queries.end(),
			[](const Query &left, const Query &right) {
			return left.target < right.target;
			});

	int queries_ptr = 0;

	// initial part
	while (queries_ptr < queries_num &&
			queries[queries_ptr].target < init_size) {
		result[queries[queries_ptr].id] =
			init_input[queries[queries_ptr].target];
		queries_ptr++;
	}

	// sort by freq, then value
	sort(frequency.begin(), frequency.end(),
			[](const Freq &left, const Freq &right) {
			if (left.freq != right.freq)
			return left.freq < right.freq;
			return left.value < right.value;
			});

	int64_t section_start = 0;
	int64_t section_end = init_size;

	int loop = 0;

	while (queries_ptr < queries_num) {
		section_start = section_end;

		// extend group
		while (loop + 1 < limit &&
				frequency[loop].freq == frequency[loop + 1].freq) {
			loop++;
		}
		loop++;

		// compute repeat
		if (loop < limit) {
			int64_t repeat =
				(int64_t)frequency[loop].freq -
				(int64_t)frequency[loop - 1].freq;

			section_end = section_start + loop * repeat;
		} else {
			section_end = INT64_MAX;
		}

		// sort prefix by value (ONLY prefix)
		sort(frequency.begin(), frequency.begin() + loop,
				[](const Freq &left, const Freq &right) {
				return left.value < right.value;
				});

		// answer queries
		while (queries_ptr < queries_num &&
				queries[queries_ptr].target < section_end) {

			int64_t offset =
				queries[queries_ptr].target - section_start;

			int index = (int)(offset % loop);

			result[queries[queries_ptr].id] =
				frequency[index].value;

			queries_ptr++;
		}
	}

	for (int value : result) {
		cout << value << '\n';
	}

	return 0;
}

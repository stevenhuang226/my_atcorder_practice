/*
 * auth: stevenhuang.dog@gmail.com
 * Help with chatGPT and official solution by sounansya
 */

#include <bits/stdc++.h>

using namespace std;

multiset<int64_t> active_columns;
int64_t clean_column;
int64_t block_width;

int64_t gap(int64_t left, int64_t right)
{
	return max((int64_t)0, right - left - block_width);
}

void add_block(int64_t column)
{
	auto it = active_columns.lower_bound(column);

	int64_t right = *it;
	int64_t left = *prev(it);

	clean_column -= (gap(left, right) -
			(gap(left, column) + gap(column, right)));

	active_columns.insert(column);
}

void del_block(int64_t column)
{
	auto it = active_columns.find(column);

	int64_t right = *next(it);
	int64_t left = *prev(it);

	clean_column += (gap(left, right) -
			(gap(left, column) + gap(column, right)));

	active_columns.erase(it);
}

int main()
{
	int64_t grid_height, grid_width;
	int64_t rect_height, rect_width;
	int64_t black_count;

	cin >> grid_height >> grid_width >> rect_height >> rect_width >> black_count;

	block_width = rect_width;

	/*	row, col, is_add */
	vector<tuple<int64_t, int64_t, int8_t>> events;
	events.reserve(2 * black_count);

	for (int i = 0; i < black_count; ++i) {
		int64_t row, col;
		scanf("%" SCNd64 " %" SCNd64, &row, &col);

		--row; --col;

		int64_t row_start = row - rect_height + 1;
		int64_t row_end = row + 1;
		int64_t col_start = col - rect_width + 1;
		int64_t col_end = col_start;

		events.emplace_back(row_start, col_start, true);
		events.emplace_back(row_end, col_end, false);
	}

	sort(events.begin(), events.end());

	int64_t total_row = grid_height - rect_height + 1;
	int64_t total_col = grid_width - rect_width + 1;

	int64_t total_dot = total_row * total_col;

	active_columns.insert(-rect_width);
	active_columns.insert(total_col);

	clean_column = total_col;

	int64_t prev_row = 0;
	int event_index = 0;

	while (event_index < events.size()) {
		int64_t curr_row = get<0>(events[event_index]);
		int64_t limi_row = min(curr_row, total_row);

		/* compute from clean_column previous computed */
		if (prev_row < limi_row) {
			int64_t row_span = limi_row - prev_row;
			int64_t disable_column = total_col - clean_column;

			total_dot -= disable_column * row_span;

			prev_row = limi_row;
		}

		while (event_index < events.size() && get<0>(events[event_index]) == curr_row) {
			int64_t event_row, event_col;
			int8_t is_add;

			tie(event_row, event_col, is_add) = events[event_index];

			if (is_add) {
				add_block(event_col);
			} else {
				del_block(event_col);
			}
			++event_index;
		}
	}

	if (prev_row < total_row) {
		int64_t row_span = total_row - prev_row;
		int64_t disable_column = total_col - clean_column;

		total_dot -= row_span * disable_column;
	}

	cout << total_dot << endl;

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int64_t pass_times, close_time;
	scanf("%" SCNd64 " %" SCNd64, &pass_times, &close_time);


	int64_t sns_time = 0;
	int64_t open_time = 0;

	for (int i = 0; i < pass_times; ++i) {
		int64_t t;
		scanf("%" SCNd64, &t);

		if (t > open_time) {
			sns_time += (t - open_time);
			open_time = t + 100;
		}
	}

	if (open_time < close_time) {
		sns_time += close_time - open_time;
	}

	printf("%" PRId64 "\n", sns_time);

	return 0;
}

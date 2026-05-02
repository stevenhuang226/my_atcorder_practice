#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	int ty;
	int by;
	int lx;
	int rx;
} Area;

static inline int max(int l, int r)
{
	return MAX(l, r);
}

static inline int max4(int a, int b, int c, int d)
{
	return MAX(max(a,b), max(c,d));
}

static inline int min(int l, int r)
{
	return MIN(l, r);
}

static inline int min4(int a, int b, int c, int d)
{
	return MIN(min(a,b), min(c,d));
}

int main()
{
	int l,r,d,u;

	scanf("%d %d %d %d", &l, &r, &d, &u);

	Area area = {
		u,
		d,
		l,
		r
	};

	int init_start = 2;

	int init_end = max4(abs(area.ty), abs(area.by), abs(area.lx), abs(area.rx));

	int64_t count = 0;

	if (area.lx <= 0 && area.rx >= 0 && area.ty >= 0 && area.by <= 0) {
		count = 1;
	}

	for (int i = init_start; i <= init_end; i += 2) {
		Area outline = {+i, -i, -i, +i};

		/*right edge*/
		if (outline.rx >= area.lx && outline.rx <= area.rx) {
			int start = MIN(outline.ty, area.ty);
			int end = MAX(outline.by + 1, area.by);
			if (start >= end) {
				count += (int64_t)(start - end + 1);
			}
		}
		/*bottom edge*/
		if (outline.by >= area.by && outline.by <= area.ty) {
			int start = MIN(outline.rx, area.rx);
			int end = MAX(outline.lx + 1, area.lx);
			if (start >= end) {
				count += (int64_t)(start - end + 1);
			}
		}
		/*left edge*/
		if (outline.lx >= area.lx && outline.lx <= area.rx) {
			int start = MIN(outline.ty - 1, area.ty);
			int end = MAX(outline.by, area.by);
			if (start >= end) {
				count += (int64_t)(start - end + 1);
			}
		}
		/*top edge*/
		if (outline.ty >= area.by && outline.ty <= area.ty) {
			int start = MIN(outline.rx - 1, area.rx);
			int end = MAX(outline.lx, area.lx);
			if (start >= end) {
				count += (int64_t)(start - end + 1);
			}
		}
	}

	printf("%" PRId64 "\n", count);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

int main()
{
	double x;
	scanf("%lf", &x);

	x /= 2;

	double pi = 3.14159265358979323846264;

	double result = x * x * pi;
	printf("%.17g\n", result);
}

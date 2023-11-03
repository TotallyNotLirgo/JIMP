#include <stdlib.h>

double calnum( double (*f)( double ), double a, double b, int n )
{
	/*
		f - function we want to find the integral of
		a - start limit
		b - end limit
		n - number of steps
	*/
	double width;
	double current_variable;
	double sum_of_areas = 0;
	width = (b - a) / n;
	/* since the extremes have different evaluations, we add them first and evaluate other variables as normal */
	sum_of_areas += f(a) * width / 2;
	sum_of_areas += f(b) * width / 2;
	while(--n) {
		sum_of_areas += f(a + n * width) * width;
	}
	return sum_of_areas;

}

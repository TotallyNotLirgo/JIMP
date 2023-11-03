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
	for(; n >= 2; n -= 2) {
		sum_of_areas += ( f(a + (n - 2) * width) + 4 * f(a + (n - 1) * width) + f(a + (n) * width) ) * width / 3;
	}	
	return sum_of_areas;

}

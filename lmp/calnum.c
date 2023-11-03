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
	for(current_variable = a + width; current_variable < b; current_variable += 2 * width)
	{
		sum_of_areas += ( f(current_variable - width) + 4 * f(current_variable) + f(current_variable + width)) * width / 3;
	}	
	return sum_of_areas;

}

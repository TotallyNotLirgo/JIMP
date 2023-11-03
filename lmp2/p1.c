#include <stdio.h>		/* dla printf */
#include <stdlib.h>		/* dla atof */

double sum(double v[], int n)
{
	/*
	 * Funkcja oblicza i zwraca sume elementow n-elementowego wektora v
	 */
	double		s = v[0];
	for(int i = n; i > 0; i--)
		s += v[i];
	return s;
}

void pwekt(double v[], int n)
{
	/* Ladne wypisywanie wektora na standardowe wyjscie */
	int		i;
	printf("[");
	for (i = 0; i < n; i++)
		printf(" %g", v[i]);
	printf(" ]");
}

int main(int argc, char *argv[])
{
	double r       [argc];	/* jesli ktos poda wiecej argumentow - bedzie bieda! */
	int i;

	int l = argc - 1;	/* liczba el. wektora */

	for (i = 1; i < argc; i++)	/* zaczynamy od drugiego el. argv */
		r[i - 1] = atof(argv[i]);	/* atof: ASCII to Float */

	pwekt(r, argc - 1);	/* można tak, ale lepiej l zmiast argc-1 */

	printf(", suma elementow = %g\n", sum(r, l));

	printf("wektor ma %d elementow\n", l);	/* zwróćmy uwagę, że funkcja sum nie "popsula" zmiennej j */

	return 0;
}

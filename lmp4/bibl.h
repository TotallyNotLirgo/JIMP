#ifndef _BIBL_H_
#define _BIBL_H_

#include <stdio.h>

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu format wektora to
 * <liczba_elementow> [ <element> ... ] np. 3 [ 1.2 4.5, 7.8]
 */
int             read(FILE * p, double v[], int max_l_e);

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double           L2(double v[], int n);

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double           dot_product(double v[], double u[], int n);

/*
 *  L1: oblicza normę L1 (wartość maksymalną z bezględnych wartości)
 */
double           L1(double v[], int n);

/*
 *  L_inf: oblicza normę Linf  (suma wartośći bezwzględnych)
 */
double           L_inf(double v[], int n);

/*
 *  multiply_by_scalar: oblicza wektor pomnożony przez skalar
 */
void             multiply_by_scalar(double v[], int n, double scalar);

/*
 * normalize: oblicza wektor znormalizowany funkcją f
 */
void             normalize_by_function(double v[], int n, double (*f)( double *, int ));

/*
 * save_vector: zapisuje wektor do pliku
 */
void             save_vector(double v[], int n, char *filename);

#endif


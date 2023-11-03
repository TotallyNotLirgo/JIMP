#include <stdio.h>
#include <stdlib.h>

#include "bibl.h"

int main(int argc, char *argv[]) {
  double w_1[10];
  double w_2[10];
  int n1;
  int n2;
  int i;

  FILE *we = argc > 1 ? fopen(argv[1], "r") : stdin; /* jesli argc > 1 to
                                                      * program zostal
                                                      * wywolany z argumentem
                                                      * - probujemy otworzyc
                                                      * taki plik do czytania */

  if (we == NULL) { /* stdin != NULL, a wiec to mozliwe tylko,
                     * gdy argv[1] zawiera cos, co nie jest nazwa
                     * istniejacego pliku */
    fprintf(stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
    exit(1);
  }
  n1 = read(we, w_1, 10); /* czytamy z wejscia wektor i pakujemy go
                           * do w_1 */

  if (n1 > 0) {
    printf("Wczytano %i-elementowy wektor:\n( ", n1);
    for (i = 0; i < n1; i++)
      printf("%f ", w_1[i]);
    printf(")\n");
  } else {
    fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n",
            n1);
    return 1;
  }

  printf("Norma L2 wczytanego wektora = %f\n", L2(w_1, n1));

  n2 = read(we, w_2, 10); /* czytamy z wejscia wektor i pakujemy go
                           * do w_2 */

  if (n2 > 0) {
    printf("Wczytano %i-elementowy wektor:\n( ", n2);
    for (i = 0; i < n2; i++)
      printf("%f ", w_2[i]);
    printf(")\n");
  } else {
    fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n",
            n2);
    return 1;
  }

  printf("Norma L2 wczytanego wektora = %f\n", L2(w_2, n2));

  if (n1 == n2) {
    printf("Iloczyn skalarny wczytanych wektorow = %f\n",
           dot_product(w_1, w_2, n1));
  } else {
    printf("Wczytane wektory maja rozna dlugosci i nie mozna ich pomnozyć "
           "przez siebie\n");
  }
  printf("Norma L1 wczytanego wektora = %f\n", L1(w_2, n2));
  printf("Norma Linf wczytanego wektora = %f\n", L_inf(w_2, n2));
  multiply_by_scalar(w_2, n2, 5);
  printf("Wektor pomnożony przez 5 da: \n( ");
  for (i = 0; i < n2; i++)
    printf("%f ", w_2[i]);
  printf(")\n");
  normalize_by_function(w_2, n2, L2);

  printf("Powstały wektor, znormalizowany przez L2 daje: \n( ");
  for (i = 0; i < n2; i++)
    printf("%f ", w_2[i]);
  printf(")\n");

  save_vector(w_2, n2, "W2.txt");

  return 0;
}

#include "bibl.h"
#include <math.h>

int read(FILE *p, double v[], int max_l_e) {
  int n, i;

  if (fscanf(p, "%i", &n) != 1 || n <= 0 || n > max_l_e) {
    return -1;
  }
  while ((i = fgetc(p)) == ' ')
    ;

  if (i != '[')
    return -1;

  for (i = 0; i < n; i++)
    if (fscanf(p, "%lf", &(v[i])) != 1)
      return -1;

  while ((i = fgetc(p)) == ' ')
    ;
  if (i != ']')
    return -1;

  return n;
}

double L2(double v[], int n) {
  int i;
  double l2 = 0;
  for (i = 0; i < n; i++)
    l2 += v[i] * v[i];
  return sqrt(l2);
}

double dot_product(double v[], double u[], int n) {
  int i;
  double dp = 0;
  for (i = 0; i < n; i++)
    dp += v[i] * u[i];
  return dp;
}

void normalize(double v[], double u[], int n) {
  int i;
  double vector_length;
  vector_length = L2(v, n);
  for (i = 0; i < n; i++)
    u[i] = v[i] / vector_length;
}

double L1(double v[], int n) {
  int i;
  double current_max = fabs(v[0]);
  for (i = 1; i < n; i++)
    current_max = current_max > fabs(v[i]) ? current_max : fabs(v[i]);
  return current_max;
}

double L_inf(double v[], int n) {
  int i;
  double sum = 0;
  for (i = 0; i < n; i++)
    sum += fabs(v[i]);
  return sum;
}

void multiply_by_scalar(double v[], int n, double scalar) {
  int i;
  for (i = 0; i < n; i++)
    v[i] *= scalar;
}

void normalize_by_function(double v[], int n, double (*f)(double *, int)) {
  double normal = f(v, n);
  int i;
  multiply_by_scalar(v, n, 1.0 / normal);
}

void save_vector(double v[], int n, char *filename) {
  int i;
  FILE *out = fopen(filename, "w");
  if (out == NULL) {
    fprintf(stderr, "nie moge pisac do %s\n", filename);
    return;
  }
  fprintf(out, "%i [", n);
  for (i = 0; i < n; i++)
    fprintf(out, " %lf", v[i]);
  fprintf(out, " ]");
}

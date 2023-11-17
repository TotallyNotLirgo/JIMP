#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv) {
    double min_val = argc > 1 ? atof(argv[1]) : 0;
    double max_val = argc > 2 ? atof(argv[2]) : 10;
    double val_delta = max_val - min_val;
    int size = argc > 3 ? atoi(argv[3]) : 10;
    int i;
    double *v = malloc(size * sizeof(double));
    srand(time(NULL));
    for(i = 0; i < size; i++)
        v[i] = min_val + ((double)rand()) / RAND_MAX * val_delta;
    printf("[");
    for(i = 0; i < size - 1; i++)
        printf("%g, ", v[i]);
    printf("%g]\n", v[size - 1]);
    
}
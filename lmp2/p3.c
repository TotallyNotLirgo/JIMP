#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
        FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

        if (in != NULL) {
                double          sum = 0;
                double          sum2 = 0;
                double          x;
                int             n = 0;

                while (fscanf(in, "%lf", &x) == 1) { 
                        sum += x;
                        sum2 += x * x;
                        n++;
                }

                fclose(in);

                printf("\tn=%d, sum=%g, avg=%g std_dev=%g\n", n, sum, sum / n, sqrt(n * sum2 - sum * sum) / n);
                return 0;
        } else
                return 1;
}

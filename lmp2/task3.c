#include <stdio.h>
#include <math.h>

double euclidean_distance(double vector[], int size)
{
        double sum_of_squares = 0;
        int i;
        for(i = 0; i < size; i++)
        {
                double reading = vector[i];
                sum_of_squares += reading * reading;
        }
        return sqrt(sum_of_squares);
}

int main(int argc, char *argv[])
{

        double reading;
        int size = 0;
        double vector[1000];

        double dist;

        FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

        if (in != NULL) {

                while (fscanf(in, "%lf", &reading) == 1) {
                        vector[size] = reading;
                        size++;
                }


                fclose(in);

                dist = euclidean_distance(vector, size);

                printf("n=%d, euc_dist=%g\n", size, dist);

                return 0;
        } else
                return 1;

}

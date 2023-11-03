#include <stdio.h>
#include <math.h>

double average(double vector[], int size)
{
        double sum = 0;
        int i;
        for(i = 0; i < size; i++)
        {
                sum += vector[i];
        }
        return (double) sum / size;
}

double standard_deviation(double vector[], int size)
{
        double sum_of_squares = 0;
        double sum = 0;
        int i;
        for(i = 0; i < size; i++)
        {
                double reading = vector[i];
                sum_of_squares += reading * reading;
                sum += reading;
        }
        return sqrt(size * sum_of_squares - sum * sum) / size;
}

int main(int argc, char *argv[])
{

        double reading;
        int size = 0;
        double vector[1000];

        double avg;
        double std_dev;

        FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

        if (in != NULL) {

                while (fscanf(in, "%lf", &reading) == 1) {
                        vector[size] = reading;
                        size++;
                }


                fclose(in);

                avg = average(vector, size);
                std_dev = standard_deviation(vector, size);

                printf("n=%d, avg=%g std_dev=%g\n", size, avg, std_dev);

                return 0;
        } else
                return 1;

}

#include <stdio.h>

double maximum(double vector[], int size)
{
        double current_max = vector[0];
        int i;
        for(i = 1; i < size; i++)
        {
                double reading = vector[i];
                current_max = current_max < reading ? reading : current_max;
        }
        return current_max;
}

double minimum(double vector[], int size)
{
        double current_min = vector[0];
        int i;
        for(i = 1; i < size; i++)
        {
                double reading = vector[i];
                current_min = current_min > reading ? reading : current_min;
        }
        return current_min;
}

int main(int argc, char *argv[])
{

        double reading;
        int size = 0;
        double vector[1000];

        double min;
        double max;

        FILE *in = argc > 1 ? fopen(argv[1], "r") : stdin;

        if (in != NULL) {

                while (fscanf(in, "%lf", &reading) == 1) {
                        vector[size] = reading;
                        size++;
                }


                fclose(in);

                min = minimum(vector, size);
                max = maximum(vector, size);

                printf("n=%d, min=%g max=%g\n", size, min, max);

                return 0;
        } else
                return 1;

}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void tabelka(double (*f) (double), double a, double b, int n, FILE * out){
        int             i;
        double          dx = (b - a) / (n - 1);

        for (i = 0; i < n; i++)
                fprintf(out, "%g %g\n", a + i * dx, f(a + i * dx));
}

double moja(double x)
{
        return 3 * x * x + 2 * x + 1;
}

int main(int argc, char **argv)
{
        char           *fun_name = argc > 1 ? argv[1] : "";
        double          a = argc > 2 ? atof(argv[2]) : 0.;
        double          b = argc > 3 ? atof(argv[3]) : 1.;
        int             n = argc > 4 ? atoi(argv[4]) : 50;

        int             i;

        FILE           *out = argc > 5 ? fopen(argv[5], "w") : stdout;

        double          (*wybrana_fun) (double)= NULL;

        double          (*funkcje[5]) (double)= {cos, sin, tan, moja, atan};
        char           *nazwy[5] = {"cos", "sin", "tan", "moja", "atan"};

        if (argc < 2) {
                printf("\n%s: tablicuje wybrana funkcje w zadanym przedziale.\n", argv[0]);
                printf("\n\tWywolanie:\n"
                       "\t\t%s <nazwa-funkcji> [ <start> [ <stop> [ <n> [ <plik> ] ] ] ]\n\n", argv[0]);
                printf("\tGdzie:\n"
                       "\t\t<nazwa-funkcji>:");
                for (i = 0; i < sizeof nazwy / sizeof nazwy[0]; i++)
                        printf("\t%s", nazwy[i]);
                printf("\n");
                printf("\t\t<start>-<stop>:  \tprzedzial - domyslnie <0,1>\n"
                     "\t\t<n>:             \tliczba krokow - domyslnie 50\n"
                 "\t\t<plik>:          \twyniki - domyslnie do stdout\n\n");
                return 0;
        }
        for (i = 0; i < sizeof nazwy / sizeof nazwy[0]; i++)
                if (strcmp(nazwy[i], fun_name) == 0)
                        wybrana_fun = funkcje[i];

        if (wybrana_fun != NULL)
                tabelka(wybrana_fun, a, b, n, out);
        else
                fprintf(stderr, "Nie znam funkcji \"%s\"\n", fun_name);

        return 0;
}

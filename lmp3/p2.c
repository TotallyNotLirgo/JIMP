#include <stdio.h>

void usun_ujemne(double *v, int *n)
{
        /* Usuwa ujemne elementy z wektora v */
        double         *u = v;
        int             l = *n;
        while (l--) {
                if (*v >= 0)    /* jeśli element jest dodatni */
                        *u++ = *v;      /* to zapamiętaj go w "nowym"
                                         * wektorze */
                else
                        (*n)--; /* w przeciwnym razie zmniejsz n */
                v++;
        }
}

void pwekt(double *v, int n)
{
        printf("[ ");
        while (n--) {
                printf("%g ", *v);
                v++;
        }
        printf("]");
}

int main()
{
        double          v[] = {-10, 0, 10, -20, 30, 1.1, -2.2, -3.3, 300.003, 1024.5};
        int             n = sizeof v / sizeof v[0];

        printf("Wektor: ");
        pwekt(v, n);
        printf(" (%d elementow)\n", n);

        usun_ujemne(v, &n);

        printf("Wektor po usunieciu ujemnych elementow: ");
        pwekt(v, n);
        printf(" (%d elementow)\n", n);

        return 0;
}

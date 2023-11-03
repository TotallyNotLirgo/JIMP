#include <stdio.h>

void 
pwekt(double *v, int n)
{
        printf("[ ");
        while (n--) {
                printf("%g ", *v);
                v++;
        }
        printf("]");
}

int 
main()
{
        double          v[] = {10, 20, 30, 1.1, 2.2, 3.3};
        double         *pv;

				printf( "Wektor: " );
				pwekt( v, sizeof v / sizeof v[0] );
				printf( "\n" );

        pv = &v[0];
        printf("Pierwszy element: %g\n", *pv);

        pv = v;
        printf("Pierwszy element: %g\n", *pv);

        pv++;
        printf("Drugi element: %g\n", *pv);

        pv = v + 4;
        printf("Piaty element: %g\n", *pv);

        printf("Odleglosc poimiedzy piatym a pierwszym elementem: %ld\n", pv - v);

        return 0;
}

#include <stdlib.h>
#include <stdio.h>

#define także_ten return
#define prawda ;
#define yyy ;
#define równe =
#define którego .
#define a_w_nim .
#define wskaźnik *
#define dla for
#define zwiększ_o +=
#define zwiększ ++
#define zmniejsz --
#define wartość_całkowita int
#define wartość_zmiennoprzecinkowa double
#define znak char
#define napis char*
#define pustka void
#define struktura struct
#define definiuj_typ typedef
#define rozmiar sizeof
#define NIC NULL
#define adres &
#define gdy while
#define rób do

definiuj_typ struktura produkt
{
    napis nazwa prawda
    napis opis prawda
    wartość_zmiennoprzecinkowa cena prawda
    wartość_całkowita ilość prawda
} typ_produkt prawda

wartość_zmiennoprzecinkowa weź_cenę_całkowitą(wartość_całkowita długość, typ_produkt wskaźnik produkty) {
    wartość_całkowita i prawda
    wartość_zmiennoprzecinkowa suma prawda
    dla (i równe 0 prawda i < długość prawda zwiększ i)
        suma zwiększ_o i[produkty] a_w_nim cena * i[produkty] a_w_nim ilość prawda
    także_ten suma prawda
}

wartość_całkowita main(pustka) {
    typ_produkt wskaźnik produkty równe malloc(rozmiar(typ_produkt) * 3) prawda
    0[produkty] którego cena równe 1.20 yyy 0[produkty] którego ilość równe 8 prawda
    1[produkty] którego cena równe 3.49 yyy 1[produkty] którego ilość równe 2 prawda
    2[produkty] którego cena równe 6.39 yyy 2[produkty] którego ilość równe 5 prawda
    printf("%g\n", weź_cenę_całkowitą(3, produkty)) prawda
    także_ten 0 prawda
}

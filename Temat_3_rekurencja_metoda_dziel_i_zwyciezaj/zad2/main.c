#include <stdio.h>
#include <stdlib.h>


int spirala(int a, int boki){
    int wynik = 0;
    int odejmowanePiksele = 0;
    for (int i = 0; i <= boki; i++)
    {
        wynik+=a-odejmowanePiksele;
        odejmowanePiksele+=2;
    }
    return wynik;
}

int spiralaReku(int a, int boki, int odejmowanePiksele) {
    if (boki < 0) {
        return 0;
    }

    return a - odejmowanePiksele + spiralaReku(a, boki - 1, odejmowanePiksele + 2);
}


int main(){
    int boki = 7;
    int a = 20;

    printf("Ilosc pikseli potrzebnych do wyswietlenia: %d \n", spirala(a,boki));
    printf("Ilosc pikseli potrzebnych do wyswietlenia Reku: %d", spiralaReku(a,boki,0));
}
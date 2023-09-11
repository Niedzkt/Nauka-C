#include <stdio.h>
#include <stdlib.h>

int* inicjalizujTablice(int rozmiar){
    return (int *)malloc(rozmiar*sizeof(int));
}

int* powiekszTablice(int *tablica, int startRozmiar, int nowyRozmiar){
    int *nowaTablica = (int *)realloc(tablica, nowyRozmiar*sizeof(int));
    if(nowaTablica==NULL){
        printf("Nie udalo sie powiekszyc tablicy! \n");
        exit(1);
    }
    return nowaTablica;
}

void wyswietlTablice(int *tablica, int rozmiar){
    printf("\nZawartosc tablicy: \n");
    for(int i = 0; i < rozmiar ; i++){
        printf("%d", tablica[i]);
    }
    printf("\n");
}

void zwolnijTablice(int *tablica){
    free(tablica);
}

int main(){
    int *tablica = inicjalizujTablice(5);
    int rozmiar = 5;
    int indeks = 0;

    printf("Wprowadz liczby calkowite: \n");
    while (1)
    {
        scanf("%d", &tablica[indeks]);

        if(tablica[indeks]==0){
            break;
        }

        indeks++;

        if(indeks==rozmiar){
            tablica = powiekszTablice(tablica,rozmiar,rozmiar+5);
        }
    }

    wyswietlTablice(tablica,indeks);
    zwolnijTablice(tablica);
    
}
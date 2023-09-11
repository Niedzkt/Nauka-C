#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 20

typedef void (*Akcja)(float);

FILE *plik;

void wypiszNaEkranie(float liczba){
    printf("%2.f", liczba);
}

void zapiszDoPliku(float liczba){
    fprintf(plik, "%2.f", liczba);
}

void przegladaTablice(float tablica[], int rozmiar, Akcja akcja){
    if(akcja == NULL){
        printf("Nie podano akcji! \n");
        return;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        akcja(tablica[i]);
    }
}

int main(){
    float tablica[ROZMIAR];
    int wybor;

    printf("Wprowadz %d liczb typu float: \n", ROZMIAR);
    for(int i=0; i<ROZMIAR; i++){
        scanf("%d", &tablica[i]);
    }

    printf("Wybierz akcje... \n");
    printf("1. Wypisz na ekran");
    printf("2. Wypisz do pliku");
    scanf("%d", &wybor);

    if(wybor==2){
        plik = fopen("liczby.txt", "w");
        if (!plik)
        {
            printf("Nie udalo sie otworzyc pliku do zapisu");
            return 1;
        }
    }
    if(wybor==1){
        przegladaTablice(tablica,ROZMIAR,wypiszNaEkranie);
    }
    else{
        przegladaTablice(tablica,ROZMIAR, zapiszDoPliku);
        fclose(plik);
        }
    return 0;
}
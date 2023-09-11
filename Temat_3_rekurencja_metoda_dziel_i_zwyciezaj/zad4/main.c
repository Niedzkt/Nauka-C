#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int*  inicjalizujTablice(int rozmiar){
    (int *)malloc(rozmiar*sizeof(int));
}

void uzupelnijTablice(int *tablica, int rozmiar){
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i]=(rand()%21)-10;
    }
}

void wyswietlTablice(int *tablica, int rozmiar){
    printf("Tablica: \n");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("%d ", tablica[i]);
    }
    printf("\n");
    
}

int liczTablice(int *tablica, int rozmiar, int cyfra){
    int wynik = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        if(tablica[i]==cyfra){
            wynik+=1;
        }
    }
    return wynik;
}

void zwolnijTablice(int *tablica){
    free(tablica);
}

int main(){
    int *tablica;
    int rozmiar;
    int cyfra;

    printf("Wprowadz rozmiar tablicy: \n");
    scanf("%d", &rozmiar);
    printf("Wprowadz cyfre szuakana w tablicy: \n");
    scanf("%d", &cyfra);

    tablica=inicjalizujTablice(rozmiar);
    uzupelnijTablice(tablica, rozmiar);
    wyswietlTablice(tablica, rozmiar);
    printf("Ilosc wystepowanej cyfry w tablicy to: %d",liczTablice(tablica, rozmiar,cyfra));
    zwolnijTablice(tablica);
}
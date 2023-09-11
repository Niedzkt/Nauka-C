#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **inicjalizujMacierz(int rozmiar){
    int **macierz = (int **)malloc(rozmiar *sizeof(int *));
    for(int i = 0; i<rozmiar; i++){
        macierz[i] = (int *)malloc(rozmiar*sizeof(int));
    }
    return macierz;
}

void wypelnijMacierz(int **macierz, int rozmiar){
    srand(time(NULL));
    for(int i = 0; i < rozmiar; i++){
        for(int j=0; j < rozmiar; j++){
            macierz[i][j]=(rand()%21) - 10;
        }
    }
}

void wyswietlMacierz(int **macierz, int rozmiar){
    printf("Zawartosc macierzy: \n");
    for(int i = 0; i<rozmiar; i++){
        for(int j=0;j<rozmiar;j++){
            printf("%4d ", macierz[i][j]);
        }
        printf("\n");
    }
}

int sumaPrzekatnej(int **macierz, int rozmiar){
    int suma=0;
    for(int i=0; i<rozmiar; i++){
        suma+=macierz[i][i];
    }
    return suma;
}

void zwolnijMacierz(int **macierz, int rozmiar){
    for(int i=0; i < rozmiar; i++){
        free(macierz[i]);
    }
}

int main(){

    int **macierz;
    int rozmiar;

    printf("Podaj rozmiar macierzy: \n");
    scanf("%d", &rozmiar);

    macierz = inicjalizujMacierz(rozmiar);
    wypelnijMacierz(macierz,rozmiar);
    wyswietlMacierz(macierz,rozmiar);

    printf("\n Suma elementow na przekatnej: %d\n", sumaPrzekatnej(macierz,rozmiar));

    zwolnijMacierz(macierz, rozmiar);

}
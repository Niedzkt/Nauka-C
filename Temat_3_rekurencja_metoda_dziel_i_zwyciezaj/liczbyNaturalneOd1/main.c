#include <stdio.h>

int suma_rekurencyjna(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + suma_rekurencyjna(n - 1);
}

int main() {
    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    printf("Suma liczb od 1 do %d: %d\n", liczba, suma_rekurencyjna(liczba));
    return 0;
}

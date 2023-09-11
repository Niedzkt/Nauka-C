#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dywan(double bok, int liczbazagniezdzen){
    double total_area = bok*bok;
    double remove_area = 0;

    for (int i = 0; i < liczbazagniezdzen; i++)
    {
        remove_area+=pow(8,i)*(bok*bok)/pow(9,i+1);
    }
    return total_area-remove_area;
    
}

int main(){
    double bok = 2.0; 
    int liczbazagniezdzen = 2;

    printf("Dywan sierpinskiego pole: %f", dywan(bok, liczbazagniezdzen));
}
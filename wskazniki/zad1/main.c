#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ciagaryt(int a, int b){
    return ((a+b)/2)*b;
}

int ciaggeo(int a, int q, int n){
    if(q==1){
        return a*n;
    }
    else
        return a*((1-pow(q, n))/(1-q));
}

void print(int valuea, int valueb){
    printf("Wartosc ciagu arytmetycznego: %d suma ciagu geometrycznego: %d", valuea, valueb);
}

int main(){
    int a = 2, b = 4, q = 4, n = 5;
    int (*ciagaryt_ptr)(int, int) = ciagaryt;
    int(*ciaggeo_ptr)(int, int, int) = ciaggeo;

    void(*print_ptr)(int, int) = NULL;
    print_ptr = print;
    int result1 = ciagaryt_ptr(a,b);
    int result2 = ciaggeo_ptr(a,q,n);
    print_ptr(result1,result2);


}
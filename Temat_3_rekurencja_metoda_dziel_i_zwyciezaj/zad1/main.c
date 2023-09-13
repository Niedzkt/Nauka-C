#include <stdio.h>
#include <stdlib.h>

int tribonacci(int n){
    if(n==0 || n == 1){
        return 0;
    }
    if (n==2)
    {
        return 1;
    }
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
}

int fibonacci(int n){
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);    
}

int silnia(int n){
    if (n == 0)
    {
        return 1;
    }
    
        return n*silnia(n-1);
    
}

int main(){

    int n = 3;
    printf("%d = wynik \n", tribonacci(n));
    printf("%d = wynik fib \n", fibonacci(n));
    printf("%d = wynik silnia \n", silnia(n));
}
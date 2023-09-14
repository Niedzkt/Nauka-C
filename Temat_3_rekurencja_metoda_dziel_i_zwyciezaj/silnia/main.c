#include <stdio.h>
#include <stdlib.h>

int silnia(int n){
    if (n==0)
    {
        return 1;
    }
    return n*silnia(n-1);
}

int fibbonaci(int n){
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return fibbonaci(n-1)+fibbonaci(n-2);
    
}

int main(int argc, char const *argv[])
{
    int n = 5;
    printf("%d \n", silnia(n));
    printf("%d", fibbonaci(n));
    return 0;
}

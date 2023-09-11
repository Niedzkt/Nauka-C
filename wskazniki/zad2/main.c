#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool allocate_array(int size, float **array){
    *array = (float*)malloc(size*sizeof(float));
    if(*array==NULL){
        return false;
    }
    return true;
}

int main(){
    float *my_array;
    int size = 5;

    if(allocate_array(size, &my_array)){
        printf("Pamiec pomyslnie zaalokowana \n");

        for(int i=0;i<size;i++){
            my_array[i] = i*1.5;
            printf("%f \n", my_array[i]);
        }

        free(my_array);
    }else
        printf("Nie udalo sie zaalokowac pamieci");

        return 0;
}
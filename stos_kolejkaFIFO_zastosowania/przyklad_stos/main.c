#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stack_node{
    int data;
    struct stack_node *next;
};

struct stack_node *push(struct stack_node *top, int data)
{
    struct stack_node *new_node = (struct stack_node *)
        malloc(sizeof(struct stack_node));
    if(NULL != new_node){
        new_node->data = data;
        new_node->next = top;
        top=new_node;
    }
    return top;
}

int pop(struct stack_node **top){
    int result = -1;
    if(NULL != *top)
    {
        result = (*top)->data;
        struct stack_node *tmp = (*top)->next;
        free(*top);
        *top=tmp;
    }
    return result;
}

int peek(struct stack_node *top){
    if(NULL!=top){
        return top->data;
    }
    fprintf(stderr, "Stos jest pusty.\n");
    return -1;
}

int main(){
    struct stack_node *top = NULL;
    srand(time(NULL));
    int i, elements = 5+rand()%6;

    printf("Szczyt stosu: %d\n", peek(top));
    for(i = 0; i<elements; i++){
        top = push(top, i);
    }
    printf("Szczyt stosu: %d\n", peek(top));
    printf("Elementy Stosu: ");

    while(NULL!= top)
        printf("%d ", pop(&top));
    printf("\n");
    printf("Szczyt Stosu: %d\n", peek(top));
    return 0;
}

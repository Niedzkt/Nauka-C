#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

struct stack_node
{
    int data[STACK_SIZE];
    struct stack_node *next;
};
/*
struct stack_node *push(struct stack_node *top, int data){
    struct stack_node *new_node = (struct stack_node *)
    malloc(sizeof(struct stack_node));
    if(NULL!=new_node){
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }
    return top;
}
*/

//podwojny wskaznik na push
void push(struct stack_node **top, int data){
    struct stack_node *new_node = (struct stack_node *)
    malloc(sizeof(struct stack_node));
    if(NULL != new_node){
        new_node->data[STACK_SIZE] = data;
        new_node->next = *top;
        *top = new_node;
    }
}

int pop(struct stack_node **top){
    int result = -1;
    if(NULL!= (*top)){
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
    printf("Stos jest pusty!");
    return -1;
}

int main(){
    struct stack_node *top = NULL;

    pop(&top);
    printf("%d \n", peek(top));
    push(&top, 3);
    push(&top, 5);
    printf("%d \n", peek(top));
    pop(&top);
    printf("%d \n", peek(top));
    pop(&top);
    printf("%d \n", peek(top));
}
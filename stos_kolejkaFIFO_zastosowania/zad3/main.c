#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack_node
{
    int data;
    struct stack_node *next;
};

bool push(struct stack_node **top, int data){
    struct stack_node *new_node = (struct stack_node *)
    malloc(sizeof(struct stack_node));
    if(NULL!=new_node){
        new_node->data = data;
        new_node->next = *top;
        *top = new_node;
        return true;
    }
    return false;
}

int pop(struct stack_node **top){
    int result = -1;
    if (NULL!=(*top))
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
    printf("Stos jest pusty! \n");
    return -1;
}

int main(){
    struct stack_node *top = NULL;
    push(&top, 3);
    printf("Brak dodanej 6 do stosu: ");
    printf("%s \n",push(&top, 6) ? "true" : "false");
    printf("Peek po dodaniu 6: ");
    printf("%d \n", peek(top));
}
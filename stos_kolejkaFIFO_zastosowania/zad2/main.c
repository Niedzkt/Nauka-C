#include <stdio.h>
#include <stdlib.h>

struct stack_node
{
    char data;
    struct stack_node *next;
};

struct stack_node *push(struct stack_node *top, char data){
    struct stack_node *new_node = (struct stack_node *)
    malloc(sizeof(struct stack_node));
    if(NULL!=new_node){
        new_node->data = data;
        new_node->next = top;
        top=new_node;
    }
    return top;
}

char pop(struct stack_node **top){
    char result = '\0';
    if (NULL!=*top)
    {
        result = (*top)->data;
        struct stack_node *tmp = (*top)->next;
        free(*top);
        *top=tmp;
    }
    return result;
}

char peek(struct stack_node *top){
    if (NULL!=top)
    {
    return top->data;
    }
    printf("Stos jest pusty!\n");
    return '\0';
}

int areParenthesisBalanced(char expr[]){
    struct stack_node *stack = NULL;
    for(int i=0; expr[i]; i++){
        if(expr[i] == '('){
            stack = push(stack, '(');
        }
        else if(expr[i] == ')'){
            if(peek(stack) != '\0' && peek(stack) == '('){ // Sprawdzamy, czy stos nie jest pusty i czy górny element to '('
                pop(&stack);
            }
            else{
                return 0; // Unbalanced
            }
        }
    }
    if(peek(stack) == '\0'){
        return 1; // Balanced
    }
    return 0; // Unbalanced
}


int main(){
    struct stack_node *top = NULL;
    char expr[100];

    printf("Podaj wyrażenie arytmetyczne: ");
    scanf("%s", expr);

    if(areParenthesisBalanced(expr)){
        printf("Nawiasy są sparowane poprawnie.\n");
    }
    else{
        printf("Nawiasy nie są sparowane poprawnie.\n");
    }

    return 0;
}
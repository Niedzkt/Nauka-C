#include <stdio.h>
#include <stdlib.h>

struct sll_node {
    int dana;
    struct sll_node *nastepny;
};

struct sll_node *insert_front(struct sll_node *front, struct sll_node *new_node){
    new_node->nastepny=front;
    return new_node;
}



int main() {
    struct sll_node* front = NULL;
    front = dodaj_na_poczatek(front, 5);
    front = dodaj_na_poczatek(front, 10);
    // Now the list contains 10 -> 5 -> NULL
    return 0;
}
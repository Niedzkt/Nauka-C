#include <stdio.h>
#include <stdlib.h>

struct sll_node {
    int dana;
    struct sll_node *nastepny;
};

void insert_after(struct sll_node *node, struct sll_node *new_node){
    new_node->nastepny = node->nastepny;
    node -> nastepny = new_node;
}
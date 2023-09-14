#include <stdio.h>
#include<stdlib.h>

struct sll_node
{
    int data;
    struct sll_node *next;
};

struct sll_node *insert_front(struct sll_node *front, struct sll_node *new_node){
    new_node->next=front;
    return new_node;
}

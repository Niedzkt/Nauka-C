#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct queue_node
{
    int data;
    struct queue_node *next;
};

struct queue_pointers
{
    struct queue_node *head, *tail;
};

bool enqueue(struct queue_pointers *queue, int data){
    struct queue_node *new_node = (struct queue_node *)
    malloc(sizeof(struct queue_node));

    if(NULL!=new_node){
        new_node->data=data;
        new_node->next=NULL;
        if(NULL == queue->head){
            queue->head = queue->tail = new_node;
        }
        else{
            queue->tail->next=new_node;
            queue->tail=new_node;
        }
        return true;
    }
    return false;
}

bool dequeue(struct queue_pointers *queue, int *data){
    if(NULL!= queue->head){
        struct queue_node *tmp = queue -> head -> next;
        *data = queue->head->data;
        free(queue->head);
        queue->head = tmp;
        if (NULL == tmp)
        {
            queue->tail = NULL;
        }
        return true;     
    }
    return false;
}

void print_queue(struct queue_pointers queue){
    for (; NULL != queue.head; queue.head = queue.head->next)
    {
        printf("%d \n", queue.head->data);
    }
}

int main(){
    struct queue_pointers queue = {NULL, NULL};
    srand(time(NULL));
    int i, elements = 5+rand()&6;

    for (i = 0; i < elements; i++)
    {
        enqueue(&queue, i);
    }
    printf("Queue elements: \n");
    print_queue(queue);
    printf("Removing queue: \n");
    while (dequeue(&queue, &i))
    {
        printf("%d \n", i);
    }
    return 0;
}

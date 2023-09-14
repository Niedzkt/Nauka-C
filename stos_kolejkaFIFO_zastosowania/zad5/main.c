#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (NULL!= new_node)
    {
        new_node->data=data;
        new_node->next=NULL;
        if (NULL == queue->head)
        {
            queue->head=new_node;
            queue->tail=new_node;
        }
        else
        {
            queue->tail->next=new_node;
            queue->tail=new_node;
        }
        return true;
    }
    return false;
}

bool dequeue(struct queue_pointers *queue, int *data){
    if (NULL!=queue->head)
    {
        struct queue_node *tmp = queue->head->next;
        *data=queue->head->data;
        free(queue->head);
        queue->head=tmp;
        if (NULL == tmp)
        {
            queue->tail=NULL;
        }
        return true;
    }
    return false;
}

void print_queue(struct queue_pointers queue){
    for ( ; NULL!= queue.head; queue.head=queue.head->next)
    {
        printf("%d \n", queue.head->data);
    }
}

int main(){
    struct queue_pointers queue = {NULL, NULL};
    int dequeue_wartosc;

    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 1);
    enqueue(&queue, 5);
    printf("Queue elements: \n");
    print_queue(queue);
    printf("Removing queue: \n");
    dequeue(&queue, &dequeue_wartosc);
    printf("%d -< dequeue dla nastepnego elementu \n", dequeue_wartosc);
    dequeue(&queue, &dequeue_wartosc);
    printf("%d -< dequeue dla nastepnego elementu \n", dequeue_wartosc);
    dequeue(&queue, &dequeue_wartosc);
    printf("%d -< dequeue dla nastepnego elementu \n", dequeue_wartosc);
    dequeue(&queue, &dequeue_wartosc);
    printf("%d -< dequeue dla nastepnego elementu \n", dequeue_wartosc);
    return 0;
}

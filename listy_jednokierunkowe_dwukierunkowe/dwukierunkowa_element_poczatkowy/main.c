#include <stdio.h>
#include <stdlib.h>

struct dll_node {
    int dana;
    struct dll_node *nastepny, *poprzedni;
};

struct dll_node *insert_front(struct dll_node *front, struct dll_node *new_node) {
    new_node->nastepny = front;
    new_node->poprzedni = NULL;  // Nowy węzeł będzie na początku, więc jego wskaźnik 'poprzedni' powinien być NULL

    if (front != NULL) {
        front->poprzedni = new_node;  // Aktualizujemy wskaźnik 'poprzedni' starego pierwszego węzła
    }

    return new_node;  // Nowy węzeł staje się początkiem listy
}

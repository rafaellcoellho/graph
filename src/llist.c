#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

typedef struct node* link;

typedef struct node 
{
    uint16_t item;
    link next;
} node;

struct llist 
{
    link head;
    link tail;
    uint32_t size;
};

llist *LinkedList_Create(void) 
{   
    llist *self = malloc(sizeof(llist));

    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
    return self;
}

void LinkedList_Destroy(llist *self)
{
    link p = self->head;
    link aux;

    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    free(self);
}

void LinkedList_Prepend(llist *self, uint16_t item)
{
    link new_node = (link) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = self->head;
    self->head = new_node;
    if(LinkedList_IsEmpty(self)) self->tail = new_node;
    self->size++;
}

void LinkedList_Append(llist *self, uint16_t item)
{
    link new_node = (link) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;
    if (LinkedList_IsEmpty(self)) {
        self->head = new_node;
        self->tail = new_node;
    } else {
        self->tail->next = new_node;
        self->tail = new_node;
    }
    self->size++;
}

void LinkedList_DeleteItem(llist *self, uint16_t item)
{
    if(self->size == 0) return;

    // Caso seja o primeiro item, já retira e termina a função
    link p = self->head;
    if (p->item == item) {
        self->head = p->next;
        free(p);
        self->size--;
        return;
    } else if (self->size == 1) { // Caso não seja, mas só tem 1 elemento
        return;
    }

    // Caso esteja no segundo pra frente ou não esteja na lista
    link p_after = p->next;
    while ( (p_after->item != item) && (p_after->next != NULL) ) {
        p = p_after;
        p_after = p_after->next;
    }

    // Esta na lista
    if (p_after->item == item) {
        if(p_after->next == NULL) p->next = NULL; // É o ultimo? 
        else p->next = p_after->next; 
        self->size--;
        free(p_after);
    }
}

void LinkedList_Show(llist *self)
{
    if(LinkedList_IsEmpty(self)) printf("\tEmpty Linked List");
    link p = self->head;

    while(p != NULL) {
        printf("\t%d->", p->item);
        p = p->next;
    }
    printf("\n");
}

bool LinkedList_IsEmpty(llist *self)
{
    if (self->size == 0) return true;
    else return false;
}

uint32_t LinkedList_GetSize(llist *self)
{
    return self->size;
}

uint16_t LinkedList_Shift(llist *self)
{
    if(LinkedList_IsEmpty(self)) return 0;
    uint16_t item = self->head->item;
    link node = self->head;
    if(LinkedList_GetSize(self) == 1) {
        self->head = NULL;
        self->tail = NULL;
    } else {
        self->head = self->head->next;
    }
    free(node);
    self->size--;
    return item;
}

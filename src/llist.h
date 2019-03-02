#ifndef _LLIST_H
#define _LLIST_H

#include <stdint.h>
#include <stdbool.h>

typedef struct llist llist;

llist *LinkedList_Create(void);
void LinkedList_Destroy(llist *self);
void LinkedList_Prepend(llist *self, uint32_t item);
void LinkedList_Append(llist *self, uint32_t item);
void LinkedList_DeleteItem(llist *self, uint32_t item);
void LinkedList_Show(llist *self);
bool LinkedList_IsEmpty(llist *self);
uint32_t LinkedList_GetSize(llist *self);
uint32_t LinkedList_Shift(llist *self);

#endif // _LLIST_H

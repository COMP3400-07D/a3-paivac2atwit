#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (!head) 
        return NULL;
    struct ll_node *node = head;
    while (node->next) {
        node = node->next;
    }
    return node;
}

/**
 * TODO: Describe what the function does
 */
int ll_size(struct ll_node *head) {
    int count = 0;
    struct ll_node *node = head;
    while (node) {
        count++;
        node = node->next;
    }
    return count;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   struct ll_node *node = head;
   while (node) {
    if (node->data == value)
        return node;
    node = node->next;
   }
   return NULL;
}

/**
 * TODO: Describe what the function does
 */
int *ll_toarray(struct ll_node *head) {
   if (!head) 
    return NULL;
    int size = ll_size(head);
    int *arr = malloc(sizeof(int) * size);
    struct ll_node *node = head;
    for (int i = 0; i < size; i++) {
        arr[i] = node->data;
        node = node->next;
    }
    return arr;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
   if (!node) 
    return NULL;
   node->data = data;
   node->next = NULL;
    return node;
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *node = head;
    while (node) {
        struct ll_node *tmp = node;
        node = node->next;
        free(tmp);
    }
}

/**
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {
    if (!head) return;
    struct ll_node *tail = ll_tail(head);
    tail->next = ll_create(data);
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (len == 0 || !data)
        return NULL;
    struct ll_node *head = ll_create(data[0]);
    struct ll_node *tail = head;
    for (int i = 1; i < len; i++) {
        tail->next = ll_create(data[i]);
        tail = tail->next;
    }
    return head;
}


/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (!head->data == value) {
        struct ll_node *new_head = head->next;
        free (head);
         return new_head;
    }
    struct ll_node *prev = head;
    struct ll_node *curr = head->next;

    while (curr) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
                return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}


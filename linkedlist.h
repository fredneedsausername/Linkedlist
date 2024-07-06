#pragma once
#include <stdlib.h>
#include <string.h>



typedef struct Linkedlist {
    struct Linkedlist* next;
    void* content;
} Linkedlist;


typedef void (*f_content_destruction)(void*);

typedef void (*f_content_traversal)(void*);

typedef int (*f_content_comparison)(void*, void*);
// returns 0 if not found
// returns anything else otherwise

size_t get_size(Linkedlist* list); // Returns the size of the list.

Linkedlist* create_node(); // Initializes and returns an empty node.

void destroy_node(Linkedlist* node, f_content_destruction fcd); // Frees all memory associated with the node.

Linkedlist* get_tail(Linkedlist* list); // Returns the last node of the list.

Linkedlist* get_at(Linkedlist* list, size_t index); // Returns the node at a specific position in the list.

Linkedlist* push_front(Linkedlist* head, void* value, size_t size); // Inserts a new node with the given value at the beginning of the list.
// returns the new head of the list

void push_back(Linkedlist* list, void* value, size_t size); // Inserts a new node with the given value at the end of the list.

void insert_after(Linkedlist* list, size_t index, void* value, size_t size); // Inserts a new node with the given value after the specified index.

Linkedlist* search_node(Linkedlist* list, void* content, f_content_comparison fcc); // Searches the node with the given content

Linkedlist* search_precedent_node(Linkedlist* list, void* content, f_content_comparison fcc); // Returns the node before the one with the specified content.

void remove_node(Linkedlist* list, void* content, f_content_comparison fcc, f_content_destruction fcd); // Removes a specific node from the list.

void remove_at(Linkedlist* list, size_t index, f_content_destruction fcd); // Removes the node at the specified position in the list.

void traverse(Linkedlist* list, f_content_traversal func); // Applies a function to each node in the list, useful for operations like printing or modifying values.

void* to_array(Linkedlist* list, size_t elementsSize); // Converts the linked list into an array of its values.

/*

reverse(list): Reverses the order of nodes in the list.
sort(list, compare): Sorts the list according to the comparison function provided.


*/

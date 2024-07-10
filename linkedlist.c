
#include "linkedlist.h"

size_t get_size(Linkedlist* list) {
    if (list == NULL) return 0;
    return 1 + get_size(list->next);
}

Linkedlist* create_node() {
    Linkedlist* ret = (Linkedlist*)calloc(sizeof(Linkedlist), 1);
    ret->next = NULL;
    ret->content = NULL;
    return ret;
}

void destroy_node(Linkedlist* node, f_content_destruction fcd) {
    fcd(node->content);
    free(node);
}

Linkedlist* get_tail(Linkedlist* list) {
    if (list->next) return get_tail(list->next);
    else return list;
}

Linkedlist* get_at(Linkedlist* list, size_t index) {
    if (index) return get_at(list->next, index - 1);
    else return list;
}

Linkedlist* push_front(Linkedlist* head, void* value, size_t size) {
    Linkedlist* inserted = create_node();
    inserted->next = head;
    memcpy(inserted->content, value, size);
    return inserted;
}

void push_back(Linkedlist* list, void* value, size_t size) {
    Linkedlist* tail = get_tail(list);
    Linkedlist* new = create_node();
    memcpy(new->content, value, size);
    tail->next = new;
}

void insert_after(Linkedlist* list, size_t index, void* value, size_t size) {
    Linkedlist* nodeindex = get_at(list, index);
    Linkedlist* oldnext = nodeindex->next;
    if (oldnext == NULL) {
        Linkedlist* newnext = create_node();
        memcpy(newnext->content, value, size);
        nodeindex->next = newnext;
    }
    else {
        Linkedlist* newnext = create_node();
        nodeindex->next = newnext;
        newnext->next = oldnext;
        memcpy(newnext->content, value, size);
    }
}

Linkedlist* search_node(Linkedlist* list, void* content, f_content_comparison fcc) {
    if (fcc(content, list->content)) {
        return list;
    }
    else {
        if (list->next == NULL) return NULL;
        else return search_node(list->next, content, fcc);
    }
}

Linkedlist* search_precedent_node(Linkedlist* list, void* content, f_content_comparison fcc) {
    if (list == NULL) return NULL;
    if (list->next == NULL) return NULL;
    if (fcc(content, list->next->content)) {
        return list;
    }
    else {
        if (list->next->next == NULL) return NULL;
        else return search_precedent_node(list->next, content, fcc);
    }
}

void remove_node(Linkedlist* list, void* content, f_content_comparison fcc, f_content_destruction fcd) {
    Linkedlist* beforeremoved = search_precedent_node(list, content, fcc);
    if (beforeremoved == NULL) return;
    Linkedlist* removed = beforeremoved->next;
    if (removed->next) {
        Linkedlist* nextremoved = removed->next;
        beforeremoved->next = nextremoved;
        destroy_node(removed, fcd);
    }
    else {
        beforeremoved->next = NULL;
        destroy_node(removed, fcd);
    }

}

void remove_at(Linkedlist* list, size_t index, f_content_destruction fcd) {
    Linkedlist* precedent = get_at(list, index - 1);
    Linkedlist* removed = precedent->next;
    Linkedlist* next = removed->next;
    destroy_node(removed, fcd);
    precedent->next = next;
}

void traverse(Linkedlist* list, f_content_traversal func) {
    if (list) {
        func(list->content);
        traverse(list->next, func);
    }
    else {
        return;
    }
}

void* to_array(Linkedlist* list, size_t elementsSize) {
    size_t size = get_size(list);
    void* ret = calloc(elementsSize, size);
    for (int i = 0; i < size; i++) {
        memcpy( ((unsigned char *)ret) + i * elementsSize, list->content, elementsSize);
        list = list->next;
    }
    return ret;
}

void clone_content(Linkedlist* node, void* content, size_t contentSize) {
    node->content = malloc(contentSize);
    memcpy(node->content, content, contentSize);
}

Linkedlist* to_list(void* array, size_t arraySize, size_t elementsSize) {
    Linkedlist* ret = create_node();
    clone_content(ret, array, elementsSize);
    Linkedlist* temp = ret;
    size_t nElements = arraySize / elementsSize;
    for (int i = 1; i < nElements; i++) {
        temp->next = create_node();
        temp = temp->next;
        clone_content(temp, ( (unsigned char *)array ) + i * elementsSize, elementsSize);
    }
    return ret;
}







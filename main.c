#include "linkedlist.h"
#include <stdio.h>

void print_double(void* content) {
    if (content == NULL) printf("Null pointer");
    printf("%lf ", *((double*)content));
}

void test_to_array() {
    double originalArray[] = { 3.14, 2.71, 1.41, 1.73 };
    Linkedlist* list = create_node();
    Linkedlist* list2 = create_node();
    Linkedlist* list3 = create_node();
    Linkedlist* list4 = create_node();
    void* content1 = (void*)(&originalArray[0]);
    void* content2 = (void*)(&originalArray[1]);
    void* content3 = (void*)(&originalArray[2]);
    void* content4 = (void*)(&originalArray[3]);
    list->content = content1;
    list2->content = content2;
    list3->content = content3;
    list4->content = content4;
    list->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;

    traverse(list, print_double);
    printf("\n");

    void* newArray = to_array(list, sizeof(double));
    double* pDouble = newArray;
    for (int i = 0; i < 4; i++) {
        printf("%lf ", *pDouble);
        pDouble++;
    }
    printf("\n");
}

void test_clone_content() {
    int a = 3;
    void* pa = (void*)(&a);
    Linkedlist* pll = create_node();
    clone_content(pll, pa, sizeof(a));
    printf("%d", *((int*)(pll->content)));
}

void test_traverse_add_one_to_double(void* doubleContent) {
    ( *( (double*) doubleContent) )++;
}

void test_traverse() {
    double originalArray[] = { 3.14, 2.71, 1.41, 1.73 };
    Linkedlist* list = create_node();
    Linkedlist* list2 = create_node();
    Linkedlist* list3 = create_node();
    Linkedlist* list4 = create_node();
    void* content1 = (void*)(&originalArray[0]);
    void* content2 = (void*)(&originalArray[1]);
    void* content3 = (void*)(&originalArray[2]);
    void* content4 = (void*)(&originalArray[3]);
    list->content = content1;
    list2->content = content2;
    list3->content = content3;
    list4->content = content4;
    list->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = NULL;

    traverse(list, test_traverse_add_one_to_double);
    traverse(list, print_double);
}

void test_to_list() {
    double originalArray[] = { 3.14, 2.71, 1.41, 1.73 };
    Linkedlist* list = to_list(originalArray, sizeof(originalArray), sizeof(double));
    traverse(list, print_double);
    printf("\n%llu", get_size(list));


}

int main() {

    return 0;
}

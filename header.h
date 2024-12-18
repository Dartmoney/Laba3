//
// Created by imako on 07.12.2024.
//

#ifndef LABA3_HEADER_H
#define LABA3_HEADER_H



typedef struct Stack_tag {
    int data;
    struct Stack_tag *back;
} Stack_t;
void printLinkedList(const Stack_t *head);
void fromArray(Stack_t **head, int *arr, int size);
int proverka(char* ss[]);
void push(Stack_t **head, int a);
int pop(Stack_t **head);
Stack_t * inclusionSort(Stack_t *stack);
int sort();
//Stack_t * getLast(Stack_t *head);
//Stack_t * getNth(Stack_t * head, int n);
//Stack_t * getLastButOne(Stack_t * head);
//void pushBack(Stack_t *head, int value);
//void insert(Stack_t *head, unsigned n, int val);
void popBack(Stack_t **head);
//void insert(Stack_t *head, unsigned n, int val);
#endif //LABA3_HEADER_H

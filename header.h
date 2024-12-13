//
// Created by imako on 07.12.2024.
//

#ifndef LABA3_HEADER_H
#define LABA3_HEADER_H



typedef struct Stack_tag {
    int data[40];
    int size;
} Stack_t;
int push(Stack_t stack, int a);
int pop(Stack_t stack);
int empty(Stack_t s);
void inclusionSort(int* num, int size);
int sort();
#endif //LABA3_HEADER_H

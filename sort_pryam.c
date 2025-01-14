#include "header.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
// Функция сортировки прямыми включениями
Stack_t * inclusionSort(Stack_t *head)
{
    int k =9;
    Stack_t *otvet = NULL;
    Stack_t *minor = NULL;
    int minik = 100000000;
    int prom;


    for (int i = 0; i < 9; i++)
    {

        if (i%2 == 0)
        {
            printLinkedList(head);
            minik = pop(&head);
        }
        else {
            printLinkedList(minor);
            minik = pop(&minor);
        }
        printf("%d\n",minik);
        for (int p=0;p<k; p++)
        {
            if (i%2 == 0)
            {
                prom = pop(&head);
            }
            else
            {
                prom = pop(&minor);
            }
            if (prom<minik)
            {
                if (i%2 == 0)
                {
                    push(&minor,minik);
                }
                else
                {
                    push(&head,minik);
                }
                minik = prom;
            }
            else
            {
                if (i % 2 == 0)
                {
                    push(&minor,prom);
                }
                else
                {

                    push(&head,prom);
                }
            }
        }
        k --;
        push(&otvet,minik);
        // рассматриваемый элемент помещаем на освободившееся место
    }
    push(&otvet,pop(&minor));
    return otvet;



}

int sort()
{
    int a[10];
    Stack_t *stack = NULL;
    char b[10];// Объявляем массив из 10 элементов
    // Вводим значения элементов массива
    size_t N = sizeof(b);
    FILE * file;
    file = fopen("data.txt", "w");
    fprintf(file,"Изначальные числа: ");
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        fprintf(file,"%4d ",a[i]);
    }
    fromArray(&stack,a,10);
    stack = inclusionSort(stack);
    printf("asss");// вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    printLinkedList(stack);
    fprintf(file,"\nОтсортированные числа: ");
    int chislo = 0;
    for (int i = 0; i < 9; i++) {
        chislo = pop(&stack);
        fprintf(file, "%4d ", chislo);
    }
    printLinkedList(stack);
    fclose(file);
    return 0;
}
void merge(Stack_t *a, Stack_t *b, Stack_t **c) {
    Stack_t tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->data < b->data) {
        *c = a;
        a = a->back;
    } else {
        *c = b;
        b = b->back;
    }
    tmp.back = *c;
    while (a && b) {
        if (a->data < b->data) {
            (*c)->back = a;
            a = a->back;
        } else {
            (*c)->back = b;
            b = b->back;
        }
        (*c) = (*c)->back;
    }
    if (a) {
        while (a) {
            (*c)->back = a;
            (*c) = (*c)->back;
            a = a->back;
        }
    }
    if (b) {
        while (b) {
            (*c)->back = b;
            (*c) = (*c)->back;
            b = b->back;
        }
    }
    *c = tmp.back;
}
void split(Stack_t *src, Stack_t **low, Stack_t **high) {
    Stack_t *fast = NULL;
    Stack_t *slow = NULL;

    if (src == NULL || src->back == NULL) {
        (*low) = src;
        (*high) = NULL;
        return;
    }

    slow = src;
    fast = src->back;

    while (fast != NULL) {
        fast = fast->back;
        if (fast != NULL) {
            fast = fast->back;
            slow = slow->back;
        }
    }

    (*low) = src;
    (*high) = slow->back;
    slow->back = NULL;
}

void mergeSort(Stack_t **head) {
    Stack_t *low  = NULL;
    Stack_t *high = NULL;
    if ((*head == NULL) || ((*head)->back == NULL)) {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}
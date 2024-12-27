//
// Created by imako on 07.12.2024.
//
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
//Stack_t * getLast(Stack_t *head) {
//    if (head == NULL) {
//        return NULL;
//    }
//    while (head->next) {
//        head = head->next;
//    }
//    return head;
//}

void push(Stack_t **head, int data) {
    Stack_t *tmp = (Stack_t *) malloc(sizeof(Stack_t));
    tmp->data = data;
    tmp->back = (*head);
    (*head) = tmp;
}
int proverka(char* ss[])
{
    int schet = 1;
    char word[7] = "--file";
    printf("%s",ss[2]);
    printf("%llu", sizeof(ss[2]));
    for(int i=1;i<20;i++)
    {
        if (ss[i] == 0)
        {
            return 0;
        }
        schet = 1;
        printf("%c\n",ss[i][0]);
        for (int p = 0;p < 6;p++)
        {
            if (ss[i][p] != word[p])
            {
                schet = 0;
            }
        }
        if (schet == 1)
        {
            return i;
        }



    }
    return 0;
}
void fromArray(Stack_t **head, int *arr, int size) {
    int i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}
int pop(Stack_t **head) {
    Stack_t * prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->data;
    (*head) = (*head)->back;
    free(prev);
    return val;
}
void printLinkedList(const Stack_t *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->back;
    }
    printf("\n");
}
//
//Stack_t * getNth(Stack_t * head, int n) {
//    int counter = 0;
//    while (counter < n && head) {
//        head = head->next;
//        counter++;
//    }
//    return head;
//}
//
//void pushBack(Stack_t *head, int value) {
//    Stack_t *last = getLast(head);
//    Stack_t *tmp = (Stack_t *) malloc(sizeof(Stack_t));
//    tmp->data = value;
//    tmp->next = NULL;
//    last->next = tmp;
//}
//Stack_t * getLastButOne(Stack_t * head) {
//    if (head == NULL) {
//        exit(-2);
//    }
//    if (head->next == NULL) {
//        return NULL;
//    }
//    while (head->next->next) {
//        head = head->next;
//    }
//    return head;
//}
//void popBack(Stack_t **head) {
//    Stack_t *lastbn = NULL;
//    //Получили NULL
//    if (!head) {
//        exit(-1);
//    }
//    //Список пуст
//    if (!(*head)) {
//        exit(-1);
//    }
//    lastbn = getLastButOne(*head);
//    //Если в списке один элемент
//    if (lastbn == NULL) {
//        free(*head);
//        *head = NULL;
//    } else {
//        free(lastbn->next);
//        lastbn->next = NULL;
//    }
//}
//
//void insert(Stack_t *head, unsigned n, int val) {
//    unsigned i = 0;
//    Stack_t *tmp = NULL;
//    //Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
//    //ошибка выбрасываться не будет, произойдёт вставка в конец
//    while (i < n && head->next) {
//        head = head->next;
//        i++;
//    }
//    tmp = (Stack_t *) malloc(sizeof(Stack_t));
//    tmp->data = val;
//    //Если это не последний элемент, то next перекидываем на следующий узел
//    if (head->next) {
//        tmp->next = head->next;
//        //иначе на NULL
//    } else {
//        tmp->next = NULL;
//    }
//    head->next = tmp;
//}
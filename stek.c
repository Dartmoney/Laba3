//
// Created by imako on 07.12.2024.
//
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int empty(Stack_t s)
{
    return s.size == 0;
}
int push(Stack_t stack, int a)
{
    if (stack.size + 1 < 20)
    {
        stack.data[stack.size + 1] = a;
        stack.size += 1;
        return 1;
    }
    printf("PEREPOLNENIE");
    return 0;
}
int pop(Stack_t stack)
{
    if (empty(stack)) {
        stack.size -= 1;
        return 1;
    }
    printf("NELZA");
    return 0;
}

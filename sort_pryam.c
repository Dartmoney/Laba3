#include "header.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
// Функция сортировки прямыми включениями
void inclusionSort(Stack_t num)
{

    // Для всех элементов кроме начального
    for (int i = 1; i < num.size; i++)
    {
        int value = num.data[i]; // запоминаем значение элемента
        int index = i;     // и его индекс
        while ((index > 0) && (num.data[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            num.data[index] = num.data[index - 1];
            index--;    // смещаем просмотр к началу массива
        }
        num.data[index] = value; // рассматриваемый элемент помещаем на освободившееся место
    }


}

int sort()
{
    Stack_t a;
    a.size = 0;
    char b[10];// Объявляем массив из 10 элементов
    // Вводим значения элементов массива
    size_t N = sizeof(b);
    FILE * file;
    file = fopen("data.txt", "w");
    fprintf(file,"Изначальные числа: ");
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a.data[i]);
        a.size += 1;
        fprintf(file,"%4d ",a.data[i]);
    }


    inclusionSort(a);  // вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    fprintf(file,"\nОтсортированные числа: ");
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%4d ", a.data[i]);
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", a.data[i]);
    getchar();
    getchar();
    fclose(file);
    return 0;
}
#include "header.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
// Функция сортировки прямыми включениями
void inclusionSort(int* num, int size)
{
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        int value = num[i]; // запоминаем значение элемента
        int index = i;     // и его индекс
        while ((index > 0) && (num[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            num[index] = num[index - 1];
            index--;    // смещаем просмотр к началу массива
        }
        num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
    }


}

int sort()
{
    int a[20];
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


    inclusionSort(a, 10);  // вызываем функцию сортировки
    // Выводим отсортированные элементы массива
    fprintf(file,"\nОтсортированные числа: ");
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%4d ", a[i]);
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    getchar();
    getchar();
    fclose(file);
    return 0;
}
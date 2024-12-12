#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main( int argc,char* argv[])
{
    SetConsoleOutputCP(65001);
    if(argc!=2)
    {
        char *str;
        FILE * file = fopen(argv[2],"r");
        fgets(str,600,file);
        printf("%s",str);
        fgets(str,600,file);
        printf("%s",str);
        return 1;
    }
    printf("Hello, World!\n");
    sort();
    return 0;
}

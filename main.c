#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main( int argc,char* argv[])
{
    SetConsoleOutputCP(65001);

    int ind = proverka(argv);
    if(ind)
    {
        char str[600];
        FILE * file = fopen(argv[ind + 1],"r");
        fgets(str,600,file);
        printf("%s",str);
        fgets(str,600,file);
        printf("%s",str);
        return 1;
    }
    sort();
    return 0;
}

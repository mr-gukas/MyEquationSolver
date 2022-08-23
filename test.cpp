#include <stdlib.h>
#include <stdio.h>
#inlcude "square.h"


// 1) создать файл с тестами
//        2
//        1 2 1 1 -1
//        1 1 1 0
// 2) считать этот файл
// 3) для считанных коэффициентов запустить свою функцию решения квадратного уравнения
// 4) сравнить ответы полученные из файла и из твоей функции

int main(void)
{
    FILE* in = NULL;
    in = fopen("input.txt", "r");
    rewind(in);

    int tcount = 0;
    fscanf(in, "%d", &tcount);

    struct Equation standart[tcount] = {};
    struct Equation current[tcount] = {};

    for (int i = 0; i < tcount; i++)
    {
        fscanf("%lf %lf %lf %lf %lf %d", standart[i].a, standart[i].b, standart[i].c,
        standart[i].x1, standart[i].x2, standart[i].count);

        current[i].a = standart[i].a;
        current[i].b = standart[i].b;
        current[i].c = standart[i].c;
        SolveTheSquare(&current[i]);

        if (standart[i].count == current[i].count && NearZero(current[i].x1 - standart[i].x1)\
        && NearZero(current[i].x2 - standart[i].x2))
            printf("Test %d was successfully passed", i+1);
        else
            printf("Test %d was failed", i+1);
    }

    fclose(in);

    return 0;
}

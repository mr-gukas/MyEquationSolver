#include <stdlib.h>
#include <stdio.h>
#include "square.h"

bool cmproots(double a, double b);
int main(void)
{
    FILE* in = NULL;
    in = fopen("input.txt", "r");
    rewind(in);

    int tcount = 0;
    struct Equation standart, current;

    fscanf(in, "%d", &tcount);
    for (int i = 0; i < tcount; i++)
    {
        fscanf(in, "%lf %lf %lf %d", &standart.a, &standart.b, &standart.c,
        &standart.count);

        if (standart.count == NO_ROOTS || standart.count == INFIN)
            while (fgetc(in) != '\n')
                continue;
        else if (standart.count == ONE_ROOT)
            fscanf(in, "%lf", &standart.x1);
        else
            fscanf(in, "%lf %lf", &standart.x1, &standart.x2);

        current.a = standart.a;
        current.b = standart.b;
        current.c = standart.c;
        SolveTheSquare(&current);

        if (standart.count == current.count && cmproots(current.x1, standart.x1)\
        && cmproots(current.x2, standart.x2))
            printf("Test %d was successfully passed\n", i+1);
        else
        {
            printf("Test %d was failed\n", i+1);
        }
    }

    fclose(in);

    return 0;
}

bool cmproots(double a, double b)
{
    if (NearZero(a - b) || (isnan(a) && isnan(b)))
        return true;
    else
        return false;
}


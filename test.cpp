#include "test.h"
#include <windows.h>

int main(void)
{
    FILE* in = fopen(TESTFILE, "r");
    if (in == NULL)
    {
        fprintf(stderr, "The file was not detected. Try again");
    }
    else
    {
        testSolveTheSquare(in);
        fclose(in);

        return 0;
    }
}

void testSolveTheSquare(FILE* in)
{
    assert (in != NULL);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    rewind(in);

    size_t tcount = 0;
    size_t passed = 0;
    struct Equation truly, current;

    fscanf(in, "%u", &tcount);
    for (size_t i = 0; i < tcount; i++)
    {
        int nroots = 0;
        fscanf(in, "%lf %lf %lf %d", &truly.a, &truly.b, &truly.c, &nroots);
        truly.count = (Roots) nroots;

        if (truly.count == NO_ROOTS || truly.count == INFIN)
        {
            eatLine(in);
        }
        else if (truly.count == ONE_ROOT)
        {
            if (fscanf(in, "%lf", &truly.x1) != 1)
            {
                fprintf(stderr, "An error in the test data. Curtailing testing");
                eatLine(in);
                break;
            }
        }
        else
        {
            if (fscanf(in, "%lf %lf", &truly.x1, &truly.x2) != 2)
            {
                fprintf(stderr, "An error in the test data. Curtailing testing");
                eatLine(in);
                break;
            }
            swapBig(&(truly.x1), &(truly.x2));
        }

        current.a = truly.a;
        current.b = truly.b;
        current.c = truly.c;
        solveTheSquare(&current);

        if (truly.count == current.count   &&
            cmpRoots(current.x1, truly.x1) &&
            cmpRoots(current.x2, truly.x2))
        {
            printf("Test num.%u was successfully ", i + 1);

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

            printf("passed\n");
            passed++;

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            printf("Test num.%u was", i + 1);

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

            printf("failed\n");
            printf("EXPECTED: Count of the roots: ");
            rootsCount(&truly);
            printf("RECEIVED: Count of the roots: ");
            rootsCount(&current);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
    }
    if (passed == tcount)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

        printf("Passed all tests! (%u/%u)\n", tcount, tcount);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        printf("Not all tests passed! (%u/%u)\n", passed, tcount);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
}

bool cmpRoots(double a, double b)
{
    return (nearZero(a - b) || (isnan(a) && isnan(b)));
}

void rootsCount(struct Equation* eqt)
{
    switch (eqt->count)
    {
        case NO_ROOTS:
            printf("no roots\n");
            break;
        case ONE_ROOT:
            printf("one root\n");
            printf("          The root: %lg\n", eqt->x1);
            break;
        case TWO_ROOTS:
            printf("two roots\n");
            printf("          The first  root: %lg\n", eqt->x1);
            printf("          The second root: %lg\n", eqt->x2);
            break;
        case INFIN:
            printf("infinite number of solutions\n");
            break;
        default:
            fprintf(stderr, "Computational error\n");
    }
}


#include "test.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        assert(0 && "Command line arguments entered incorrectly");
    }
    else
    {
        FILE* in = fopen(argv[1], "r");
        if (in == NULL)
        {
            assert (0 && "The file was not detected. Try again");
        }
        else
        {
            testSolveTheSquare(in);
            fclose(in);
        }
    }

    return 0;
}

void testSolveTheSquare(FILE* in)
{
    assert (in != NULL);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    rewind(in);

    size_t tCount = 0;
    size_t passed = 0;
    struct Equation truly = {}, current = {};

    fscanf(in, "%u", &tCount);
    for (size_t i = 0; i < tCount; i++)
    {
        int nRoots = 0;
        if (fscanf(in, "%lf %lf %lf %d", &truly.a, &truly.b, &truly.c, &nRoots) != 4)
        {
            assert (0 && "An error in the test data. Curtailing testing");
        }

        truly.count = (Roots) nRoots;

        if (truly.count == NO_ROOTS || truly.count == INFIN)
        {
            eatLine(in);
        }
        else if (truly.count == ONE_ROOT)
        {
            if (fscanf(in, "%lf", &truly.x1) != 1)
            {
                assert(0 && "An error in the test data. Curtailing testing");
            }
        }
        else
        {
            if (fscanf(in, "%lf %lf", &truly.x1, &truly.x2) != 2)
            {
                assert (0 && "An error in the test data. Curtailing testing");
            }
            swapDescending(&truly.x1, &truly.x2);
        }

        current.a = truly.a;
        current.b = truly.b;
        current.c = truly.c;
        solveTheSquare(&current);

        if (truly.count == current.count   &&
            cmpRoots(current.x1, truly.x1) &&
            cmpRoots(current.x2, truly.x2))
        {
            printf("Test number %u was successfully ", i + 1);

            setGreen(hConsole);

            printf("passed\n");
            passed++;

            colorReset(hConsole);
        }
        else
        {
            printf("Test number %u was successfully ", i + 1);

            setRed(hConsole);

            printf("failed\n");

            colorReset(hConsole);

            printf("EXPECTED: Count of the roots: "); printRootsCount(&truly);
            printf("RECEIVED: Count of the roots: "); printRootsCount(&current);
        }
    }
    if (passed == tCount)
    {
        setGreen(hConsole);

        printf("Passed all tests! (%u/%u)\n", tCount, tCount);

        colorReset(hConsole);
    }
    else
    {
        setRed(hConsole);

        printf("Tests passed: %u/%u\n", passed, tCount);

        colorReset(hConsole);
    }
}

bool cmpRoots(double a, double b)
{
    return nearZero(a - b) || (isnan(a) && isnan(b));
}

void printRootsCount(const struct Equation* eqt)
{
    switch (eqt->count)
    {
        case NO_ROOTS:
            printf("no roots\n");
            break;

        case ONE_ROOT:
            printf("one root\n");
            printf("          The root: %lg\n",        eqt->x1);
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
            assert(0 && "Computational error");
    }
}

void setRed(HANDLE hConsole)
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

void setGreen(HANDLE hConsole)
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void colorReset(HANDLE hConsole)
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}


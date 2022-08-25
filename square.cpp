#include "square.h"
#include <string.h>

int main(void)
{
    struct Equation eqt = {};
    int choice = 0;

    while ((choice = getChoice()) != 'q')
    {
        puts("Enter the square, linear and free coefficients of the quadratic equation:");

        if (scanf("%lf %lf %lf", &eqt.a, &eqt.b, &eqt.c) != 3)
        {
            eatLine(stdin);
            fprintf(stderr, "Input error! Try again\n");
        }
        else
        {
            if (!eatLine(stdin))
            {
                fprintf(stderr, "There may have been an error when entering data. Try again\n");
            }
            else
            {
            solveTheSquare(&eqt);
            showSolution(&eqt);
            }
        }
    }
    puts("The program is completed");

    return 0;
}
void showSolution(const struct Equation* const eqt)
{

    assert (eqt != NULL);

    switch (eqt->count)
    {
        case NO_ROOTS:
            printf("This equation has no solutions\n");
            break;

        case ONE_ROOT:
            printf("This equation has one solution: x = %5.3lg\n", eqt->x1);
            break;

        case TWO_ROOTS:
            printf("This equation has two solutions:\n");
            printf("    x1 = %5.3lg\n", eqt->x1);
            printf("    x2 = %5.3lg\n", eqt->x2);
            break;

        case INFIN:
            puts("This equation has an infinite number of solutions");
            break;

        default:
            fprintf(stderr, "Error. Number of roots: %d\n", eqt->count);
    }
}

int getChoice(void)
{
    int choice = 0;

    printf("****Select an operation:\n");
    printf("s)Solve the quadratic equation        q)Quit the program\n");

    while ((choice = getchar()) != EOF)
    {
        eatLine(stdin);
        if (strchr("sq", choice) == NULL)
        {
            puts("Invalid value entered. Enter s or q:");
        }
        else
            break;
    }

    if (choice == EOF)
    {
        printf("The end of the file has been reached\n");
        choice = 'q';
    }

    return choice;
}


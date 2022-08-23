#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "square.h"

int main(void)
{
    struct Equation eqt;
    int choice = 0;

    while ((choice = GetChoice()) != 'b')
    {
        puts("Введите по порядку квадратный, линейный и свободный коэффициенты квадратного уравнения:");

        if (scanf("%lf %lf %lf", &eqt.a, &eqt.b, &eqt.c) != 3)
        {
            eatline();
            fprintf(stderr, "Ошибка ввода! Попробуйте заново\n");
        }
        else
        {
            SolveTheSquare(&eqt);
            ShowSolution(&eqt);
            eatline();
        }
    }
    puts("Программа завершена");

    return 0;
}

void SolveTheSquare(struct Equation* eqt)
{
    double a = eqt->a;
    double b = eqt->b;
    double c = eqt->c;
    if (NearZero(a))
    {
        if (NearZero(b))
        {
            eqt->count = (NearZero(c)) ? INFIN : NO_ROOTS;
        }
        else
        {
            eqt->x1 = -a / b;
            if (NearZero(eqt->x1))
                eqt->x1 = 0.0f;
            eqt->count = ONE_ROOT;
        }
    }
    else
    {
        double discr = b*b - 4*a*c;
        if (discr < 0.0f)
        {
            eqt->count = NO_ROOTS;
        }
        else
        {
            eqt->x1 = (-b + sqrt(discr)) / (2 * a);
            eqt->x2 = (-b - sqrt(discr)) / (2 * a);
            eqt->count = (NearZero(eqt->x1 - eqt->x2)) ? ONE_ROOT : TWO_ROOTS;
        }
    }
}

void ShowSolution(struct Equation* eqt)
{

    assert (eqt != NULL);

    switch (eqt->count)
    {
        case NO_ROOTS:
            printf("Данное уравнение не имеет решений\n");
            break;
        case ONE_ROOT:
            printf("Данное уравнение имеет единственное решение: x = %lf\n", eqt->x1);
            break;
        case TWO_ROOTS:
            printf("Данное уравнение имеет два решения:\n");
            printf("    x1 = %lf\n", eqt->x1);
            printf("    x2 = %lf\n", eqt->x2);
            break;
        case INFIN:
            puts("Данное уравнение имеет бесконечное множество решений");
            break;
        default:
            fprintf(stderr, "Ошибка. Количество корней: %d\n", eqt->count);
    }
}

int GetChoice(void)
{
    int choice = 0;

    printf("****Выберите операцию:\n");
    printf("a)Решить квадратное уравнение        b)Выйти из программы\n");

    while ((choice = getchar()) != EOF)
    {
        eatline();
        if (strchr("ab", choice) == NULL)
        {
            puts("Введено неверное значение. Введите a или b:");
        }
        else
            break;
    }

    if (choice == EOF)
        choice = 'b';

    return choice;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

bool NearZero(double x)
{
    return (fabs(x) < 0.00001) ? true : false;
}

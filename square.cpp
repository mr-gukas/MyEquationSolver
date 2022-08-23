#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

enum roots {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INFIN = -1};
bool NearZero(double x);
roots SolveTheSquare(double quadr, double line, double free, double* x1, double* x2);
void ShowSolution(int count, double* x1, double* x2);
int GetChoice(void);
void eatline(void);

int main(void)
{
    double quadr = NAN, line = NAN, free = NAN;
    double x1 = NAN, x2 = NAN;
    int choice = 0;
    roots count = NO_ROOTS;

    while ((choice = GetChoice()) != 'b')
    {
        puts("Введите по порядку квадратный, линейный и свободный коэффициенты квадратного уравнения:");

        if (scanf("%lf %lf %lf", &quadr, &line, &free) != 3)
        {
            eatline();
            printf("Ошибка ввода! Попробуйте заново\n");
        }
        else
        {
            count = SolveTheSquare(quadr, line, free, &x1, &x2);
            ShowSolution(count, &x1, &x2);
            eatline();
        }
    }
    puts("Программа завершена");

    return 0;
}

roots SolveTheSquare(double quadr, double line, double free, double* x1, double* x2)
{
    if (NearZero(quadr))
    {
        if (NearZero(line))
        {
            return (NearZero(free)) ? INFIN : NO_ROOTS;
        }
        else
        {
            *x1 = -free / line;
            if (NearZero(*x1))
                *x1 = 0.0f;
            return ONE_ROOT;
        }
    }
    else
    {
        double discr = line*line - 4*quadr*free;
        if (discr < 0.0f)
        {
            return NO_ROOTS;
        }
        else
        {
            *x1 = (-line + sqrt(discr)) / (2 * quadr);
            *x2 = (-line - sqrt(discr)) / (2 * quadr);
            return (NearZero(*x1 - *x2)) ? ONE_ROOT : TWO_ROOTS;
        }
    }
}

void ShowSolution(int count, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    switch (count)
    {
        case NO_ROOTS:
            printf("Данное уравнение не имеет решений\n");
            break;
        case ONE_ROOT:
            printf("Данное уравнение имеет единственное решение: x = %lf\n", *x1);
            break;
        case TWO_ROOTS:
            printf("Данное уравнение имеет два решения:\n");
            printf("    x1 = %lf\n", *x1);
            printf("    x2 = %lf\n", *x2);
            break;
        case INFIN:
            puts("Данное уравнение имеет бесконечное множество решений");
            break;
        default:
            printf("Ошибка. Количество корней: %d\n", count);
    }
}

int GetChoice(void)
{
    int choice = 0;

    printf("****Выберите операцию:\n");
    printf("a)Решить квадратное уравнение        b)Выйти из программы\n");

    while ((choice = getchar()) != EOF) {
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

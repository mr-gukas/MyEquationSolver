#include "square.h"

void solveTheSquare(struct Equation* eqt)
{

    assert (eqt != NULL);

    double a = eqt->a;
    double b = eqt->b;
    double c = eqt->c;
    if (nearZero(a))
    {
        if (nearZero(b))
        {
            eqt->count = (nearZero(c)) ? INFIN : NO_ROOTS;
        }
        else
        {
            eqt->x1 = -c / b;
            if (nearZero(eqt->x1))
            {
                eqt->x1 = 0.0f;
            }
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
            if (nearZero(eqt->x1 - eqt->x2))
            {
                eqt->count = ONE_ROOT;
                eqt->x2 = NAN;
            }
            else
            {
                swapDescending(&(eqt->x1), &(eqt->x2));
                eqt->count = TWO_ROOTS;
            }
        }
    }
}

bool nearZero(double x)
{
    return fabs(x) < CLOSE_TO_ZERO;
}

void eatLine(FILE* file)
{
    assert(file != NULL);

    while (fgetc(file) != '\n')
        continue;
}

void swapDescending(double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (*x1 < *x2)
    {
        double temp = *x2;
        *x2 = *x1;
        *x1 = temp;
    }
}





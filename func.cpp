#include <math.h>
#include "square.h"

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
            eqt->x1 = -c / b;
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
            if (NearZero(eqt->x1 - eqt->x2))
            {
                eqt->count = ONE_ROOT;
                eqt->x2 = NAN;
            }
            else
                eqt->count = TWO_ROOTS;
        }
    }
}

bool NearZero(double x)
{
    return (fabs(x) < CLOSE_TO_ZERO) ? true : false;
}


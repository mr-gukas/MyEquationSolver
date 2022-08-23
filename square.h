#include <stdbool.h>

const double CLOSE_TO_ZERO = 0.00001; ///<The value below which we use for zero
///@brief A class that determines the number of roots of the equation
enum Roots
{
    NO_ROOTS, ///<There are no root
    ONE_ROOT, ///<There is one root
    TWO_ROOTS,///<There are two roots
    INFIN = -1///<There are infinite number of roots
};

///Determines whether a floating-point number can be considered zero
///@return Close to zero or not
bool NearZero(double x);

/**
Solves a quadratic equation based on the coefficients entered by the user
@param [in] eqt Pointer to the structure containing the necessary coefficients
*/
void SolveTheSquare(struct Equation* eqt);

/**
Outputs the roots of the quadratic equation
@param [in] eqt Pointer to a structure containing the necessary roots and their number
*/
void ShowSolution(struct Equation* eqt);

/**
Displays a menu in which the user determines further actions
@return The choice made by the user
*/
int GetChoice(void);

///To switch to a new line
void eatline(void);

///@brief A data structure that includes equation coefficients, roots, and number of roots
struct Equation
{
    double a = NAN;///<The quadratic coefficient
    double b = NAN;///<The linear coefficient
    double c = NAN;///<The free coefficient
    double x1 = NAN;///<The first root
    double x2 = NAN;///<The second root
    Roots count = NO_ROOTS;///<Count of the roots
};

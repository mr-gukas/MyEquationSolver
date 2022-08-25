#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

const double CLOSE_TO_ZERO = 1e-5; ///<The value below which we use as zero

///@brief A class that determines the number of roots of the equation
enum Roots
{
    NO_ROOTS, ///<There are no root
    ONE_ROOT, ///<There is one root
    TWO_ROOTS,///<There are two roots
    INFIN = -1///<There are infinite number of roots
};

/**
 * @brief Determines whether a floating-point number can be considered zero
 * @param [in] Floating point number
 * @return Close to zero or not
 */
bool nearZero(const double x);

/**
 * @brief Solves a quadratic equation based on the coefficients entered by the user
 * @param [out] eqt Pointer to the structure containing the necessary data
 * @return Returns nothing
 */
void solveTheSquare(struct Equation* const eqt);

/**
 * @brief Outputs the roots of the quadratic equation
 * @param [out] eqt Pointer to a structure containing the necessary data
 * @return Returns nothing
 */
void showSolution(const struct Equation* const eqt);

/**
 * @brief Displays a menu in which the user determines further actions
 * @return The choice made by the user
 */
int getChoice(void);

/**
 * @brief To appear to a new line in the stream
 * @param [in] file from where "eat" the line
 * @return Return true if remains of the line contains only space symbols
 */
bool eatLine(FILE* const file);

///@brief A data structure that includes equation coefficients, roots, and number of roots
struct Equation
{
    double a = NAN;///<The quadratic coefficient
    double b = NAN;///<The linear coefficient
    double c = NAN;///<The free coefficient
    Roots count = NO_ROOTS;///<Count of the roots
    double x1 = NAN;///<The greater root
    double x2 = NAN;///<The less root
};

/**
 * @brief A function that swaps two real numbers, if the second is greater than the first
 * @param [out] Two floating point numbers
 * @return Returns nothing
 */
void swapDescending(double* x1, double* x2);

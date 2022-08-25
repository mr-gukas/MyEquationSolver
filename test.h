#include <stdlib.h>
#include "square.h"
#include <windows.h>

/**
 * @brief A function that checks whether the roots obtained as a result of calculations match the real roots
 * @return Match/Don't match
 */
bool cmpRoots(const double a, const double b);

/**
 * @brief A function that tests data received from a file
 * @param [in] A pointer to a file containing tests
 * @return Returns nothing
 */
void testSolveTheSquare(FILE* const in);

/**
 * A function that outputs the number of roots of the equation
 * @param [in] A pointer to the structure, the number of roots of which you want to output
 * @return Returns nothing
 */
void printRootsCount(const struct Equation* const eqt);

/**
 * @brief Make red output text
 */
void setRed(HANDLE const hConsole);

/**
 * @brief Make green output text
 */
void setGreen(HANDLE const hConsole);

/**
 * @brief Reset color of output text
 */
void colorReset(HANDLE const hConsole);

/**
 * @brief A function that collapses testing in case of erroneous data
 * @param [in] Number of the test
 * @return Returns nothing
 */
void testDataError(const size_t testNum);




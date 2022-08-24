#include <stdlib.h>
#include "square.h"
#include <windows.h>

/**
 * @brief A function that checks whether the roots obtained as a result of calculations match the real roots
 * @return Match/Don't match
 */
bool cmpRoots(double a, double b);

/**
 * @brief A function that tests data received from a file
 * @param [in] A pointer to a file containing tests
 * @return Returns nothing
 */
void testSolveTheSquare(FILE* in);

/**
 * A function that outputs the number of roots of the equation
 * @param [in] A pointer to the structure, the number of roots of which you want to output
 * @return Returns nothing
 */
void printRootsCount(const struct Equation* eqt);

///@brief Name of the test data file
const char TESTFILE[] = "test.txt";

/**
 * @brief Make red output text
 */
void setRed(HANDLE hConsole);

/**
 * @brief Make green output text
 */
void setGreen(HANDLE hConsole);

/**
 * @brief Reset color of output text
 */
void colorReset(HANDLE hConsole);





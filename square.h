#include <stdbool.h>


enum Roots {NO_ROOTS, ONE_ROOT, TWO_ROOTS, INFIN = -1};
bool NearZero(double x);
/**
Решает квадратное уравнение на основе введённых пользователем коэффициентов
@param [in] eqt Указатель на структуру, содержащую необходимые коэффициенты
*/
void SolveTheSquare(struct Equation* eqt);
/**
Выводит корни квадратного уравнения
@param [in] eqt Указатель на структуру, содержащую необходимые корни и их количество
*/
void ShowSolution(struct Equation* eqt);
/**
Выводит меню, в котором пользователь определяет дальнейшие действия
@param [out] Выбор, сделанный пользователем
*/
int GetChoice(void);
///Для перехода на новую строку
void eatline(void);
///@brief Структура данных, включающая в себя коэффициенты уравнения, корни и количество корней
struct Equation
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    Roots count = NO_ROOTS;
};

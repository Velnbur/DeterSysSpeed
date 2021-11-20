#include "funcs.h"

double calc_rate(double num, double empty, int oper)
{
    return 1 / ((num/oper) - empty);
}

double calc_average(double(*f)(), int amount)
{
    int i;
    double sum = 0;
    for(i = 0; i < amount; ++i)
        sum += f();
    return sum / amount;
}

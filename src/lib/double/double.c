#include "double.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "../funcs/funcs.h"

static int OPERATIONS = 0;
static int OPER_DIV = 0;

static double calc_empty()
{
    int i;
    clock_t start, end;
    double tmp, a = 54345.0, b = 23423.9, c = 3.5;
    double d = 54345.0, e = 23423.9, f = 3.5;
    double g = INT_MAX, h = INT_MIN, k = 3;
    double l = 29, m = 233, n = INT_MAX-3;
    start = clock();
    for(i = 0; i < OPERATIONS; ++i) {
        a = tmp;
        b = a;
        c = d;
        d = e;
        e = c;
        f = a;

        g = tmp;
        h = g;
        k = h;
        l = k;
        m = l;
        n = l;
    }
    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

static double calc_sum()
{
    int i;
    double tmp, a = 54345.0, b = 23423.9, c = 3.5;
    double d = 54345.0, e = 23423.9, f = 3.5;
    double g = INT_MAX, h = INT_MIN, k = 3;
    double l = 29, m = 233, n = INT_MAX-3;

    clock_t start, end;
    start = clock();

    for(i = 0; i < OPERATIONS; ++i) {
        tmp = c + a;
        a = d + tmp;
        b = e + tmp;
        d = a + b;
        e = tmp + d;
        f = e + tmp;

        g = h + k;
        h = d + n;
        l = k + tmp;
        n = m + l;
        m = g + h;
        k = l + k;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

static double calc_min()
{
    int i;
    double tmp, a = 54345.0, b = 23423.9, c = 3.5;
    double d = 54345.0, e = 23423.9, f = 3.5;
    double g = INT_MAX, h = INT_MIN, k = 3;
    double l = 29, m = 233, n = INT_MAX-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPERATIONS; ++i) {
        tmp = c - a;
        a = d - tmp;
        b = e - tmp;
        d = a - b;
        e = tmp - d;
        f = e - tmp;

        g = h - k;
        h = d - n;
        l = k - tmp;
        n = m - l;
        m = g - h;
        k = l - k;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

static double calc_mul()
{
    int i;
    double tmp, a = 54345.0, b = 23423.9, c = 3.5;
    double d = 54345.0, e = 23423.9, f = 3.5;
    double g = INT_MAX, h = INT_MIN, k = 3;
    double l = 29, m = 233, n = INT_MAX-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = c * a;
        a = d * tmp;
        b = e * tmp;
        d = a * b;
        e = tmp * d;
        f = e * tmp;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

static double calc_div()
{
    int i;
    double tmp, a = 54345.0, b = 23423.9, c = 3.5;
    double d = 54345.0, e = 23423.9, f = 3.5;
    double g = INT_MAX, h = INT_MIN, k = 3;
    double l = 29, m = 233, n = INT_MAX-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = a / b;
        a = tmp / c;
        b = c / d;
        tmp = d / tmp;
        d = tmp / b;
        e = f / c;

        tmp = g / e;
        g = tmp / f;
        h = k / d;
        tmp = l / n;
        l = tmp / l;
        m = n / b;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

void calc_double(struct result *res, int oper, int amount)
{
    OPERATIONS = oper;
    OPER_DIV = oper / 100;
    double empty = calc_average(calc_empty, amount) / OPERATIONS / 12.0;

    res->sum = calc_rate(calc_average(calc_sum, amount)/ 12.0, empty, OPERATIONS);
    res->div = calc_rate(calc_average(calc_div, amount)/ 12.0, empty, OPER_DIV);
    res->min = calc_rate(calc_average(calc_min, amount)/ 12.0, empty, OPERATIONS);
    res->mul = calc_rate(calc_average(calc_mul, amount)/6, empty, OPER_DIV);
}

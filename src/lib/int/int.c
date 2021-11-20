#include "int.h"
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "../funcs/funcs.h"

static int OPERATIONS = 0;
static int OPER_DIV = 0;


static double calc_empty()
{
    int i;
    clock_t start, end;
    int tmp, a = INT_MAX, b = INT_MIN, c = 3;
    int d = 29, e = 233, f = INT_MAX-3;
    int g = INT_MAX, h = INT_MIN, k = 3;
    int l = 29, m = 233, n = INT_MAX-3;

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
    int tmp, a = INT_MAX, b = INT_MIN, c = 3;
    int d = INT_MIN+2, e = INT_MAX-3, f = 123;
    int g = INT_MAX, h = INT_MIN, k = 3;
    int l = 29, m = 233, n = INT_MAX-3;
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
    int tmp, a = INT_MAX, b = INT_MIN, c = 3;
    int d = INT_MIN+2, e = INT_MAX-3, f = 3122;
    int g = INT_MAX, h = INT_MIN, k = 3;
    int l = 29, m = 233, n = INT_MAX-3;
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
    int tmp, a = INT_MAX, b = INT_MIN, c = 3;
    int d = INT_MIN+2, e = INT_MAX-3, f = 123;
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
    int tmp, a = 3, b = 11, c = 17;
    int d = 29, e = 234, f = INT_MAX-3;
    int g = 3, h = 11, k = 17;
    int l = 29, m = 234, n = INT_MAX-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = a / b;
        a = tmp / b;
        b = c / b;
        tmp = d / e;
        d = tmp / e;
        e = f / e;

        tmp = g / h;
        g = tmp / h;
        h = k / h;
        tmp = l / m;
        l = tmp / m;
        m = n / m;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

void calc_int(struct result *res, int oper, int amount)
{
    OPERATIONS = oper;
    OPER_DIV = OPERATIONS / 100;
    double empty = calc_average(calc_empty, amount) / OPERATIONS / 12.0;

    res->sum = calc_rate(calc_average(calc_sum, amount) / 12.0, empty, OPERATIONS);
    res->div = calc_rate(calc_average(calc_div, amount) / 12.0, empty, OPER_DIV);
    res->min = calc_rate(calc_average(calc_min, amount) / 12.0, empty, OPERATIONS);
    res->mul = calc_rate(calc_average(calc_mul, amount) / 6.0, empty, OPER_DIV);
}

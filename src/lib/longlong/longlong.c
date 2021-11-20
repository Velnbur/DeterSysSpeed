 #include "longlong.h"
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
    long long tmp, a = LLONG_MAX, b = LLONG_MIN, c = 11;
    long long d = LLONG_MAX-1, e = LLONG_MIN, f = INT_MAX-3;
    long long g = LLONG_MAX, h = LLONG_MIN, k = 11;
    long long l = LLONG_MAX-1, m = LLONG_MIN, n = INT_MAX-3;
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
    long long tmp, a = LLONG_MAX, b = LLONG_MIN, c = 11;
    long long d = LLONG_MAX-1, e = LLONG_MIN, f = INT_MAX-3;
    long long g = LLONG_MAX, h = LLONG_MIN, k = 11;
    long long l = LLONG_MAX-1, m = LLONG_MIN, n = INT_MAX-3;
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
    long long tmp, a = LLONG_MAX, b = LLONG_MIN, c = 11;
    long long d = LLONG_MAX-1, e = LLONG_MIN, f = INT_MAX-3;
    long long g = LLONG_MAX, h = LLONG_MIN, k = 11;
    long long l = LLONG_MAX-1, m = LLONG_MIN, n = INT_MAX-3;
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
    long long tmp, a = LLONG_MAX, b = LLONG_MIN, c = 11;
    long long d = LLONG_MAX-1, e = LLONG_MIN, f = INT_MAX-3;
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
    long long tmp, a = 33, b = 11111, c = LONG_MAX;
    long long d = 29, e = 234, f = INT_MAX-3;
    long long g = 33, h = 11111, k = LONG_MAX;
    long long l = 29, m = 234, n = INT_MAX-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = a / b;
        a = tmp / m;
        b = c / b;
        tmp = d / e;
        d = tmp / m;
        e = f / e;

        tmp = g / h;
        g = tmp / b;
        h = k / h;
        tmp = l / e;
        l = tmp / m;
        m = n / m;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

void calc_longlong(struct result *res, int oper, int amount)
{
    OPERATIONS = oper;
    OPER_DIV = OPERATIONS / 100;
    double empty = calc_average(calc_empty, amount) / OPERATIONS / 12;

    res->sum = calc_rate(calc_average(calc_sum, amount) / 12, empty, OPERATIONS);
    res->div = calc_rate(calc_average(calc_div, amount) / 12, empty, OPER_DIV);
    res->min = calc_rate(calc_average(calc_min, amount) / 12, empty, OPERATIONS);
    res->mul = calc_rate(calc_average(calc_mul, amount) / 6, empty, OPER_DIV);
}

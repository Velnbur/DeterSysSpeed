#include "float.h"
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
    float tmp, a =  12738127.00, b = 123123.0, c = 3.1;
    float d =  1245698.00, e = 123.0, f = 2344.1;
    float g = 1242.1, h = 1243.4, k = 3;
    float l = 29, m = 233, n = 12341.0-3;
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
    float tmp, a =  12738127.00, b = 123123.0, c = 3.1;
    float d =  1245698.00, e = 123.0, f = 2344.1;
    float g = 1242.1, h = 1243.4, k = 3;
    float l = 29, m = 233, n = 12341.0-3;
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
    float tmp, a =  12738127.00, b = 123123.0, c = 3.1;
    float d =  1245698.00, e = 123.0, f = 2344.1;
    float g = 1242.1, h = 1243.4, k = 3;
    float l = 29, m = 233, n = 12341.0-3;
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
    float tmp, a =  12738127.00, b = 123123.0, c = 3.1;
    float d =  1245698.00, e = 123.0, f = 2344.1;
    float g = 1242.1, h = 1243.4, k = 3;
    float l = 29, m = 233, n = 12341.0-3;
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
    float tmp, a =  12738127.00, b = 123123.0, c = 3.1;
    float d =  1245698.00, e = 123.0, f = 2344.1;
    float g = 1242.1, h = 1243.4, k = 3;
    float l = 29, m = 233, n = 12341.0-3;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = a / b;
        a = tmp / d;
        b = a / b;
        tmp = d / c;
        d = tmp / a;
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

void calc_float(struct result *res, int oper, int amount)
{
    OPERATIONS = oper;
    OPER_DIV = OPERATIONS / 100;
    double empty = calc_average(calc_empty, amount) / OPERATIONS / 12;

    res->sum = calc_rate(calc_average(calc_sum, amount) / 12, empty, OPERATIONS);
    res->div = calc_rate(calc_average(calc_div, amount)/ 12, empty, OPER_DIV);
    res->min = calc_rate(calc_average(calc_min, amount)/ 12, empty, OPERATIONS);
    res->mul = calc_rate(calc_average(calc_mul, amount)/ 6, empty, OPER_DIV);
}

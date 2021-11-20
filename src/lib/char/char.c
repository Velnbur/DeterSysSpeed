#include "char.h"
#include <stdlib.h>
#include <time.h>
#include "../funcs/funcs.h"

static int OPERATIONS = 0;
static int OPER_DIV = 0;

static double calc_empty()
{
    int i;
    clock_t start, end;
    char tmp, a = 'a', b = 'b'+1, c = 'c';
    char d = 29, e = 25, f = 123;
    char g = 'g', h = 'h'+1, k = 'k';
    char l = 29, m = 25, n = 123;
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
    char tmp, a = 'a', b = 'b'+1, c = 'c';
    char d = 111, e = 23, f = 123;
    char g = 'g', h = 'h'+1, k = 'k';
    char l = 29, m = 25, n = 123;

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
    char tmp, a = 'a', b = 'b'+1, c = 'c';
    char d = 111, e = 23, f = 123;
    char g = 'g', h = 'h'+1, k = 'k';
    char l = 29, m = 25, n = 123;
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
    char tmp, a = 'a', b = 'b'+1, c = 'c';
    char d = 111, e = 23, f = 123;
    char g = 'g', h = 'h'+1, k = 'k';
    char l = 29, m = 25, n = 123;
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
    char tmp, a = 'a', b = 'b', c = 'c';
    char d = 29, e = 53, f = 123;
    char g = 'g', h = 'h'+1, k = 'k';
    char l = 29, m = 25, n = 123;
    clock_t start, end;
    start = clock();

    for(i = 0; i < OPER_DIV; ++i) {
        tmp = a / b;
        a = tmp / h;
        b = c / b;
        tmp = d / m;
        d = tmp / e;
        e = f / m;

        tmp = g / h;
        g = tmp / b;
        h = k / b;
        tmp = l / e;
        l = tmp / e;
        m = n / m;
    }

    end = clock();
    return ((double)end - start) / CLOCKS_PER_SEC;
}

void calc_char(struct result *res, int oper, int amount)
{
    OPERATIONS = oper;
    OPER_DIV = oper / 100;
    double empty = calc_average(calc_empty, amount) / oper / 12;

    res->sum = calc_rate(calc_average(calc_sum, amount) / 12, empty, OPERATIONS);
    res->div = calc_rate(calc_average(calc_div, amount)/ 12, empty, OPER_DIV);
    res->min = calc_rate(calc_average(calc_min, amount)/ 12, empty, OPERATIONS);
    res->mul = calc_rate(calc_average(calc_mul, amount)/ 6, empty, OPER_DIV);
}

#include "result.h"
#include <stdio.h>
#include <stdlib.h>

struct result *new_result_empty()
{
    struct result *tmp =
        (struct result *)malloc(sizeof(struct result));
    tmp->div = 0;
    tmp->min = 0;
    tmp->sum = 0;
    tmp->mul = 0;
    return tmp;
}

static void draw_line(int pers)
{
    int tmp = (int)(((double)pers)/100*65);
    for(int i = 0; i < 65; ++i) {
        if(i < tmp)
            putc('#', stdout);
        else
            putc(' ', stdout);
    }
}

void print_result(struct result *res)
{
    printf("%e\n%e\n%e\n%e\n", res->sum, res->min, res->mul, res->div);
}

void print_results(struct result **res)
{
    char alg[4] = {'+', '-', '*', '/'};
    const char* types[5] = {"char", "int", "long", "float", "double"};
    double max = 0;
    int i;
    for(i = 0; i < 5; ++i) {
        if(max < res[i]->sum)
            max = res[i]->sum;
        if(max < res[i]->min)
            max = res[i]->min;
        if(max < res[i]->mul)
            max = res[i]->mul;
        if(max < res[i]->div)
            max = res[i]->div;
    }
    for(i = 0; i < 5; ++i) {
        int pers = (int)(res[i]->sum/max*100);
        printf("%c %-6s %.6e ", alg[0], types[i], res[i]->sum);
        draw_line(pers);
        printf(" %d%%", pers);
        putc('\n', stdout);

        pers = (int)(res[i]->min/max*100);
        printf("%c %-6s %.6e ", alg[1], types[i], res[i]->min);
        draw_line(pers);
        printf(" %d%%", pers);
        putc('\n', stdout);

        pers = (int)(res[i]->mul/max*100);
        printf("%c %-6s %.6e ", alg[2], types[i], res[i]->mul);
        draw_line(pers);
        printf(" %d%%", pers);
        putc('\n', stdout);

        pers = (int)(res[i]->div/max*100);
        printf("%c %-6s %.6e ", alg[3], types[i], res[i]->div);
        draw_line(pers);
        printf(" %d%%", pers);
        putc('\n', stdout);
    }
}

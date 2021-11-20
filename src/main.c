#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/result/result.h"
#include "lib/int/int.h"
#include "lib/char/char.h"
#include "lib/longlong/longlong.h"
#include "lib/float/float.h"
#include "lib/double/double.h"

static const int OPERATIONS = 10*1000*1000;

int main()
{
    int i;
    struct result *results[5];
    int amount = 10;

    for(i = 0; i < 5; ++i)
       results[i] = new_result_empty();

    calc_char(results[0], OPERATIONS, amount);
    calc_int(results[1], OPERATIONS, amount);
    calc_longlong(results[2], OPERATIONS, amount);
    calc_float(results[3], OPERATIONS, amount);
    calc_double(results[4], OPERATIONS, amount);

    print_results(results);

    return 0;
}

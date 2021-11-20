#ifndef RESULT_H_SENTRY
#define RESULT_H_SENTRY

struct result {
    double sum, min, div, mul;
};

void print_result(struct result *res);

struct result *new_result_empty();

void print_results(struct result **res);

#endif // RESULT_H_SENTRY

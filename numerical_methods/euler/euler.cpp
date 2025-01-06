#include <cmath>

#include "euler.h"

#define N 2

void EulerDynamic(double t, double *st, double *der)
{
    der[0] = st[1];
    der[1] = 5 + -2 * st[1];
}

void EulerStep(double t, double *st, double step)
{
    double yIn[N] = {};
    EulerDynamic(t, st, yIn);
    for (int i = 0; i < N; i++)
        st[i] += yIn[i] * step;
}

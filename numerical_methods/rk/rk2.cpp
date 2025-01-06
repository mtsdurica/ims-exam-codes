#include <cmath>

#include "rk2.h"

#define N 2

void Dynamic(double t, double *st, double *der)
{
    der[0] = st[1];
    // der[1] = (cos(st[1]) - 7 * st[0]) / (double)5.0;
    der[1] = 5 + -2 * st[0];
}

void Step(double t, double *st, double step)
{
    double k1[N] = {};
    double k2[N] = {};
    double start[N] = {};
    double yIn[N] = {};

    for (int i = 0; i < N; i++)
        start[i] = st[i];

    Dynamic(t, st, yIn);

    for (int i = 0; i < N; i++)
    {
        k1[i] = yIn[i];
        st[i] = start[i] + k1[i] * (1.0 / 2.0) * step;
    }

    Dynamic(t + (1.0 / 2.0) * step, st, yIn);
    for (int i = 0; i < N; i++)
    {
        k2[i] = yIn[i];
        st[i] = start[i] + k2[i] * step;
    }
}

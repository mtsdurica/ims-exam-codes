#include <cstdio>

#include "../numerical_methods/euler/euler.h"

int main()
{
    double time = 0.0;
    double end = 20.0;
    double step = 1.0;
    double st[] = {1.0, 1.0};

    while (time < end)
    {
        printf("Time: %lf Y': %g Y: %g\n", time, st[1], st[0]);

        if (time + step > end)
            step = end - time;

        EulerStep(time, st, step);
        time += step;
    }
    printf("Time: %lf Y': %g Y: %g\n", time, st[1], st[0]);

    return 0;
}

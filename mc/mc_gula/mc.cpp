#include <cmath>
#include <cstdio>
#include <cstdlib>

int main()
{
    srand(0);

    double tries = 10000;
    double r = 20.0;

    double area = (4.0 / 3.0) * M_PI * r * r * r;
    printf("Analyticke: %f\n", area);

    double sum;

    for (int i = 0; i < tries; i++)
    {
        double x = (double)rand() / ((double)RAND_MAX + 1);
        x *= r;
        double y = (double)rand() / ((double)RAND_MAX + 1);
        y *= r;
        double z = (double)rand() / ((double)RAND_MAX + 1);
        z *= r;

        if ((x * x + y * y + z * z) < (r * r))
            sum++;
    }
    double avg = sum / tries;

    avg = avg * r * r * r * 8;

    printf("Monte Carlo: %f\n", avg);
    return 0;
}

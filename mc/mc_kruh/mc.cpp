#include <cmath>
#include <cstdio>
#include <cstdlib>

double Uniform()
{
    return (double)rand() / ((double)RAND_MAX + 1);
}

int main()
{
    srand(0);

    double tries = 10000;
    double r = 20.0;

    double area = M_PI * r * r;
    printf("Analyticke: %f\n", area);

    double sum;

    for (int i = 0; i < tries; i++)
    {
        double x = Uniform() * r;
        double y = Uniform() * r;

        if ((x * x + y * y) < (r * r))
            sum++;
    }
    double avg = sum / tries;

    avg = avg * r * r * 4;

    printf("Monte Carlo: %f\n", avg);
    return 0;
}

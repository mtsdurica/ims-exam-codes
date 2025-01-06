#include <cstdio>

#include "../numerical_methods/euler/euler.h"

void event(double time, double *st)
{
    (void)printf("Time: %f; State: %f %f\n", time, st[1], st[0]);
}

int main()
{
    double time = 0.0;
    double end = 50.0;
    double normStep = 0.1;
    double minStep = 0.01;
    double st[] = {1.0, 1.0};
    double step = normStep;

    while (time < end)
    {
        double stBackup[2];
        for (int i = 0; i < 2; i++)
            stBackup[i] = st[i];

        double timeBackup = time;

        bool stateCond = st[1] > st[0];

        EulerStep(time, st, step);
        time += step;

        bool newCond = st[1] > st[0];

        if (stateCond != newCond) // Zistujeme ci sme neprekrocili nejaky moment, ktory treba zaznamenat
        {
            if (step > minStep) // Prekrocili sme moment ale nemame ocakavanu presnost
            {
                // Vraciame zalohovane hodnoty
                time = timeBackup;
                for (int i = 0; i < 2; i++)
                    st[i] = stBackup[i];

                step /= 2; // Zmensenie kroku

                // Dokrocenie
                if (step < minStep)
                    step = minStep;
            }
            else
            {
                event(time, st); // Logujeme event
                step = normStep; // Reset kroku
            }
        }
    }

    return 0;
}

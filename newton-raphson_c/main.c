#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float evaluacion(float x)
{
    float fx = x*x*x - 2*x - 5;
    return fx;
}

float derivada(float x)
{
    float dy = 3*x*x - 2;
    return dy;
}

int main()
{
    float error = 100;
    float x[100];
    x[0] = 1;
    int c = 1;

    printf("\n \t i \txi \tf(xi) \tE. Abs \tE. Rel\n\t-----------------------------------------\n");


    while(error>=1 || error<=-1)
    {
        x[c]= x[c-1] - ((evaluacion(x[c-1]))/(derivada(x[c-1])));

        error=sqrt(pow((((x[c]-x[c-1])/x[c])*100),2));

        printf("\t %d", c-1);
        printf("\t %.2f", x[c-1]);
        printf("\t %.2f", evaluacion(x[c-1]));
        printf("\t %.2f", sqrt(pow((((2.09-x[c-1])/2.09)),2)));
        printf("\t %.2f\n", error);

        c++;

    }
    return 0;
}

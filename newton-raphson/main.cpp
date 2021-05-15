#include <bits/stdc++.h>

using namespace std;

double evaluacion(double x)
{
    double fx = x*x*x - 2*x - 5;
    return fx;
}

double derivada(double x)
{
    double dy = 3*x*x - 2;
    return dy;
}

int main()
{
    double error = 100;
    double x[100];
    x[0] = 1;
    int c = 1;

    cout << endl << " \ti \t xi \t f(xi) \t E. Abs \t%E. Rel" << endl << endl;
    cout << "\t------------------------------------------------" << endl << endl;


    while(error>=1)
    {
        x[c]= x[c-1] - ((evaluacion(x[c-1]))/(derivada(x[c-1])));

        error=(abs((x[c]-x[c-1])/x[c]))*100;

        cout << " \t" << c-1 << " \t" << fixed << setprecision(2) << x[c-1] << " \t" << fixed << setprecision(2) << evaluacion(x[c-1]) << " \t" << fixed << setprecision(4) << abs((2.09-x[c-1])/2.09) << " \t\t" << fixed << setprecision(2) << error << " %" << endl;

        c++;

    }

    return 0;
}

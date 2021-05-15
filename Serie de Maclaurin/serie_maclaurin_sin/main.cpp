#include <bits/stdc++.h>

using namespace std;

double errorreal(double valor_medido, double x)
{
    double et=(sin(x))-valor_medido;               //Error real = sin x - resultado de la serie.
    return et;
}

double porcentajeerror(double valor_medido, double x)
{
    double pe=((errorreal(valor_medido, x))/(sin(x)))*100;      //% de error = (Error real/(sin x))*100
    return pe;
}

double errorrelativo(double etant, double etact)        //Error relativo porcentual = (1-(Error real anterior/Error real actual))*100
{
    double ea=(1-(etant/etact))*100;
    return ea;
}

double factorial(int numero)
{
    double fact=1;
    for(int i=1; i<=numero; i++)
    {
        fact=fact*i;
    }
    return fact;
}

double valorabsoluto(double n)
{
    if(n<0)
    {
        n=n*-1;
    }
    return n;
}

int main()
{
    int iteraciones;
    cout << "Ingresa la cantidad de iteraciones: ";
    cin >> iteraciones;

    double argumento=0;
    cout << "Argumento del seno: ";
    cin >> argumento;

    double sinx=argumento;
    double erant=0;
    double c=1;

    cout << endl;
    cout << "Iteracion" << "\t\t" << "Aproximacion" << "\t\t" << "Error verdadero" << "\t\t" << "Error relativo porcentual verdadero" << "\t\t" << "Error relativo porcentual" << endl << endl;

    cout << c << "\t\t\t" << setprecision(10) << sinx << "\t\t\t" << setprecision(4) << errorreal(sinx, argumento) << "\t\t" << setprecision(4) << valorabsoluto(porcentajeerror(sinx, argumento)) << " %" << "\t\t\t\t" << setprecision(4) << valorabsoluto(errorrelativo(erant, sinx)) << " %" << endl;

    erant=sinx;
    c++;

    for(int i=0; i<iteraciones*2; i=i+2)
    {
        sinx=sinx+(((pow(-1, c-1))*(pow(argumento, i+3)))/(factorial(i+3)));        //Sumatoria de la serie.


        cout << c << "\t\t\t" << setprecision(10) << sinx << "\t\t\t" << setprecision(4) << errorreal(sinx, argumento) << "\t\t" << setprecision(4) << valorabsoluto(porcentajeerror(sinx, argumento)) << " %" << "\t\t\t\t" << setprecision(4) << valorabsoluto(errorrelativo(erant, sinx)) << " %" << endl;

        erant=sinx;
        c++;
    }
    return 0;
}

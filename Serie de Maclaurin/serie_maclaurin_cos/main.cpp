#include <bits/stdc++.h>

using namespace std;

double errorreal(double valor_medido, double x)
{
    double et=(cos(x))-valor_medido;    //Error real = cos x - resultado de la serie.
    return et;
}

double porcentajeerror(double valor_medido, double x)
{
    double pe=((errorreal(valor_medido, x))/(cos(x)))*100;      //% de error = (Error real/(cos x))*100
    return pe;
}

double errorrelativo(double etant, double etact)        //Error relativo porcentual = (1-(Aproximacion anterior/Aproximacion actual))*100
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
    cout << "Ingresa la cantidadde iteraciones: ";
    cin >> iteraciones;

    double argumento=0;
    cout << "Argumento del coseno: ";
    cin >> argumento;

    double cosx=1;
    double erant=0;
    double c=1;

    cout << endl;
    cout << "Iteracion" << "\t\t" << "Aproximacion" << "\t\t" << "Error verdadero" << "\t\t" << "Error relativo porcentual verdadero" << "\t\t" << "Error relativo porcentual" << endl << endl;

    for(int i=0; i<iteraciones*2; i=i+2)
    {
        cosx=cosx+(((pow(-1, c))*(pow(argumento, i+2)))/(factorial(i+2)));        //Sumatoria de la serie.


        cout << c << "\t\t\t" << setprecision(5) << cosx << "\t\t\t" << setprecision(7) << errorreal(cosx, argumento) << "\t\t" << setprecision(6) << valorabsoluto(porcentajeerror(cosx, argumento)) << " %" << "\t\t\t\t        " << setprecision(3) << valorabsoluto(errorrelativo(erant, cosx)) << " %" << endl;

        erant=cosx;
        c++;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

double errorreal(double valor_medido, double p)
{
    double et=(pow(2.718281828,p))-valor_medido;    //Error real = e^p - resultado de la serie.
    return et;
}

double porcentajeerror(double valor_medido, double p)
{
    double pe=((errorreal(valor_medido, p))/(pow(2.718281828,p)))*100;      //% de error = (Error real/(e^p))*100
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
    cout << "Ingresa la cantidadde iteraciones: ";
    cin >> iteraciones;

    double potencia=0;
    cout << "Potencia a la que se elevara e: ";
    cin >> potencia;

    double epn=0;
    double erant=0;

    cout << endl;
    cout << "Iteracion" << "\t\t" << "Aproximacion" << "\t\t" << "Error verdadero" << "\t\t" << "Error relativo porcentual verdadero" << "\t\t" << "Error relativo porcentual" << endl << endl;

    for(int i=0; i<iteraciones; i++)
    {
        epn=epn+((pow(potencia, i))/(factorial(i)));        //Sumatoria de la serie.


        cout << i+1 << "\t\t\t" << setprecision(6) << epn << "\t\t\t" << setprecision(7) << errorreal(epn, potencia) << "\t\t" << setprecision(6) << valorabsoluto(porcentajeerror(epn, potencia)) << " %" << "\t\t\t\t        " << setprecision(3) << valorabsoluto(errorrelativo(erant, epn)) << " %" << endl;

        erant=epn;
    }
    return 0;
}

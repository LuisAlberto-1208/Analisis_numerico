#include <bits/stdc++.h>

using namespace std;


int main()
{
    double xl, xu;
    int grado, iteraciones;
    cout << "Limite menor: ";
    cin >> xl;
    cout << "Limite mayor: ";
    cin >> xu;
    cout << endl;
    cout << "Grado la funcion: ";
    cin >> grado;
    cout << endl;
    cout << "Iteraciones: ";
    cin >> iteraciones;
    cout << endl;


    double Funcion[grado];

    for(int i=grado; i>=0; i--)
    {
        cout << "x^" << i << " = ";
        cin >> Funcion[i];
        cout << endl;
    }


    double RES[iteraciones][6];



    /*

    CODIFICACION


    La matriz RES significa RESULTADOS


    - xl o limite menor -> RES[i][0];
    - xu o limite mayot -> RES[i][1];
    - xr o raiz aproximada -> RES[i][2];
    - f(xl) -> RES[i][3];
    - f(xr) -> RES[i][4];
    - f(xl)*f(xr) -> RES[i][5];


    */



    for(int i=0; i<iteraciones; i++)
    {
        RES[i][0]=xl;
        RES[i][1]=xu;
        RES[i][2]=(xl+xu)/2;        //xr


//-----------------------------------------------------------

//  f(xl)=

        RES[i][3]=0;

        for(int j=0; j<=grado; j++)
        {
            RES[i][3]=RES[i][3]+Funcion[j]*pow(xl, j);
        }
//-----------------------------------------------------------

//-----------------------------------------------------------

//  f(xr)=

        RES[i][4]=0;

        for(int j=0; j<=grado; j++)
        {
            RES[i][4]=RES[i][4]+Funcion[j]*pow(RES[i][2], j);
        }

//-----------------------------------------------------------

        RES[i][5]=RES[i][3]*RES[i][4];  //f(xl)*f(xr)


//CONDICIONES PARA ELEGIR EL SENTIDO DE LA BISECCION
//(ELEGIR QUE VALOR VA A TOMAR xr)
//SI f(xl)*f(xr) > 0, xl toma el valor de xr, pero si
//f(xl)*f(xr) < 0, xu es el que toma el valor de xr


        if(RES[i][5]>0)
        {
            xl=RES[i][2];
        }
        else if(RES[i][5]<0)
        {
            xu=RES[i][2];
        }
    }

//  IMPRESION DE LA TABLA

    for(int i=0; i<iteraciones; i++)
    {
        for(int j=0; j<6; j++)
        {
            cout << fixed << setprecision(4) << RES[i][j] << "\t\t";
        }
        cout << endl;
    }

//  LA ULTIMA RAIZ APROXIMADA

    cout << endl << endl << endl << "La raiz aproximada es " << RES[iteraciones-1][2] << endl;

    return 0;
}

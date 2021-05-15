#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Ingresa la cantidad de puntos... " << endl;
    cin >> n;
    double XY[n][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            XY[i][j] = 0;
        }
    }
    cout << endl;
    double x;
    cout << "Ingresa el valor en el que sera evaluado..." << endl;
    cin >> x;
    cout << endl;
    cout << "Ingresa los pares coordenados" << endl << "x y" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> XY[i][0] >> XY[i][1];
    }

    int c = 0; // CALCULA LAS DIFERENCIAS DIVIDIDAS
    int p = 0;
    for(int i=2; i<=n; i++)
    {
        for(int j=i-c; j>=0; j--)
        {
             XY[j][i]=(XY[j+1][i-1]-XY[j][i-1])/(XY[j+1+p][0]-XY[j][0]);
        }
        c=c+2;
        p++;
    }


    cout << endl << "Diferencias divididas" << endl << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout << XY[i][j] << " \t";
        }
        cout << endl;
    }

    double A[n];

    for(int i=0; i<n; i++)  //GUARDA EN UN ARREGLO LOS RESULTADOS DE
    {                       //(X-X0), (X-X0)(X-X1), (X-X0)...(X-XN)
        A[i]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            A[i]=A[i]*(x-XY[j][0]);
        }
    }

    double suma=XY[0][1];

    for(int i=1; i<n; i++)
    {
        suma=suma+A[i]*XY[0][i+1];
    }

    cout << endl << endl << "El polinomio de interpolacion evaluado en " << x << " es " << suma << endl;
    return 0;
}

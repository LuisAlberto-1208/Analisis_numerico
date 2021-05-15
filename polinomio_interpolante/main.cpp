#include <bits/stdc++.h>

using namespace std;

int main()
{
    int puntos;

    cout << "Ingrese la cantidad de puntos: ";

    cin >> puntos;

    cout << endl << "Ingrese los puntos (x, y)" << endl;

    double MatrizPuntos[puntos][2];

    for(int i=0; i<puntos; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> MatrizPuntos[i][j];
        }
    }

    double A[puntos][puntos]; //Matriz A (Coeficientes de las ecuaciones del sistema)

    for(int i=0; i<puntos; i++)
    {
        for(int j=0; j<puntos; j++)
        {
            A[i][j]=pow((MatrizPuntos[i][0]), j);
        }
    }

    double b[puntos]; //Vector solucion

    for(int i=0; i<puntos; i++)
    {
        b[i]=MatrizPuntos[i][1];
    }


    double Id[puntos][puntos]; //Matriz identidad

    for(int i=0; i<puntos; i++)
    {
        for(int j=0; j<puntos; j++)
        {
            Id[i][j]=0;
        }
    }
    for(int i=0; i<puntos; i++)
    {
        Id[i][i]=1;
    }


    //Inversa de la matriz
    double pibote=0;

    for(int i=0; i<puntos; i++)
    {
        pibote=A[i][i];
        for(int j=0; j<puntos; j++)
        {
            A[i][j]=A[i][j]/pibote;
            Id[i][j]=Id[i][j]/pibote;
        }

        double aux=0;

        for(int k=0; k<puntos; k++)
        {
            if(i!=k)
            {
                aux=A[k][i];

                for(int l=0; l<puntos; l++)
                {
                    A[k][l]=A[k][l]-(aux*(A[i][l]));
                    Id[k][l]=Id[k][l]-(aux*(Id[i][l]));
                }
            }
        }
    }



    double aux[puntos];


    for(int i=0; i<puntos; i++)
    {
        aux[i]=0;
    }



    //Multiplicacion de matriz por vector Id*b
    for(int i=0; i<puntos; i++)
    {
        for(int j=0; j<puntos; j++)
        {
            aux[i]=aux[i]+(Id[i][j]*b[j]);
        }
    }

    //Coeficientes
    cout << "Los coeficientes de la funcion, de menor a mayor exponente son los siguientes" << endl;
    for(int i=0; i<puntos; i++)
    {
        cout << "C" << i << " = " << aux[i] << endl;
    }

    return 0;
}

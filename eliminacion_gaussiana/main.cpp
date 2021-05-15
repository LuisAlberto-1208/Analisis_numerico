#include <iostream>

using namespace std;

int main()
{


    //PARA ECUACIONES DE N * N


    int x, y;
    cout << "Cuantas ecuaciones tienes?";
    cout << endl;
    cin >> x;
    y=x;
    cout << endl;

    // MATRIZ AUMENTADA

    double A[x][y+1];

    cout << endl << "Ingresa la matriz aumentada..." << endl;
    cout << endl;

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            cin >> A[i][j];
        }
    }


    cout << endl;


    // ELIMINACION GAUSSIANA


    double pivote=0;

    for(int i=0; i<x; i++)
    {
        pivote=A[i][i];
        for(int j=0; j<=y; j++)
        {
            A[i][j]=A[i][j]/pivote;
        }

        double aux=0;

        for(int k=0; k<x; k++)
        {
            if(i<k)
            {
                aux=A[k][i];

                for(int l=0; l<=y; l++)
                {
                    A[k][l]=A[k][l]-(aux*(A[i][l]));
                }
            }
        }
    }

    // IMPRIME LA MATRIZ AUMENTADA LUEGO DE LA ELIMINACION GAUSSIANA

    cout << "\t\t " << "-------------------------------" << endl;
    cout << "\t\t ";
    for(int i=0; i<y; i++)
    {
        cout << "x" << i+1 << "\t ";
    }

    cout << " R " << endl;

    cout << "\t\t " << "-------------------------------" << endl;

    for(int i=0; i<x; i++)
    {
        cout << "\t\t ";
        for(int j=0; j<=y; j++)
        {
            cout << A[i][j] << "\t ";
        }
        cout << endl;
    }


    cout << "\t\t " << "-------------------------------" << endl;


    // SE MULTIPLICAN LOS RESULTADOS POR LOS 1 DE LA MATRIZ

    for(int i=0; i<x; i++)
    {
        A[i][i]=A[i][i]*A[i][y];
    }



    // EL NUEVO VALOR DE LOS NUMEROS EN LA DIAGONAL SE MULTIPLICAN
    // POR TODOS LOS QUE HAY ARRIBA DE ELLOS, PERO ANTES DE PASAR
    // A LA SIGUIENTE COLUMNA, AL SIGUIENTE NUMERO DE LA DIAGONAL SE
    // LE RESTAN TODOS LOS NUMEROS QUE SE ENCUENTRAN A SU IZQUIERDA
    // Y SE GUARDA EN LA MISMA DIAGONAL, EL RESULTADO ES EL VALOR DE CADA
    // VARIABLE.


    for(int i=y-1; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            A[j-1][i]=A[j-1][i]*A[i][i];
        }
        for(int k=i; k<x; k++)
        {
            A[i-1][i-1]=A[i-1][i-1]-A[i-1][k];
        }
    }


    // SE IMPRIMEN LOS VALORES DE CADA INCOGNITA

    cout << "\t " << "----------------------------------------------" << endl;

    for(int i=0; i<x; i++)

    {
        cout << "\t " << "x" << i+1 << " = " << A[i][i];
    }

    cout << endl << "\t " << "----------------------------------------------" << endl;

    return 0;
}

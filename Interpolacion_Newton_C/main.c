#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Ingresa la cantidad de puntos...\n");
    scanf("%d", &n);
    float XY[n][n+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            XY[i][j] = 0;
        }
    }
    printf("\n");
    float x;
    printf("Ingresa el valor en el que sera evaluado...\n");
    scanf("%f", &x);
    printf("\nIngresa los pares coordenados\nx y\n");
    for(int i=0; i<n; i++)
    {
        scanf("%f", &XY[i][0]);
        scanf("%f", &XY[i][1]);
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


    printf("Diferencias divididas\n\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            printf("%.2f \t", XY[i][j]);
        }
        printf("\n");
    }

    float A[n];

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

    float suma=XY[0][1];

    for(int i=1; i<n; i++)
    {
        suma=suma+A[i]*XY[0][i+1];
    }

    printf("El polinomio de interpolacion evaluado en %f es %f\n", x, suma);
    return 0;
}

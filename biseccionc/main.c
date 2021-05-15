#include <stdio.h>
#include <stdlib.h>

int main()
{
    float xl, xu;
    int grado, iteraciones;
    printf("Limite menor: ");
    scanf("%f", &xl);
    printf("Limite mayor: ");
    scanf("%f", &xu);
    printf("\n Grado de la funcion: ");
    scanf("%d", &grado);
    printf("\n Iteraciones: ");
    scanf("%d", &iteraciones);
    printf("\n");


    float Funcion[grado];

    for(int i=grado; i>=0; i--)
    {
        printf("x^ %d = ", i);
        scanf("%f", &Funcion[i]);
        printf("\n");
    }


    float RES[iteraciones][6];



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
            printf("%.2f      ", RES[i][j]);
        }
        printf("\n");
    }

//  LA ULTIMA RAIZ APROXIMADA

    printf("\n\n\n La raiz aproximada es %f\n", RES[iteraciones-1][2]);


    return 0;
}

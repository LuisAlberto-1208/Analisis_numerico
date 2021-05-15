#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Cantidad de puntos...\n");
    scanf("%d", &n);
    printf("\n");

    float x;
    printf("Introduce el valor de x en el que se evaluara la interpolacion\n");
    scanf("%f", &x);
    printf("\n");

    int a, b, c;
    printf("Introduce tres ordenes en los que se evaluara\n");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("\n");

    float X[n], Y[n];
    printf("Introduce los pares coordenados separados por un espacio\n");
    for(int i=0; i<n; i++)
    {
        scanf("%f, %f", &X[i], &Y[i]);
    }
    printf("\n");



    //Orden a

    float sumaa=0, numa=1, dena=1, conta=0;
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=a; j++)
        {
            if(j!=conta)
            {
                numa = numa * (x-X[j]);
                dena = dena * (X[i]-X[j]);
            }
        }
        sumaa = sumaa + (numa/dena)*Y[i];
        conta++;
        numa = 1;
        dena = 1;
    }

    //Orden b

    float sumab=0, numb=1, denb=1, contb=0;
    for(int i=0; i<=b; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(j!=contb)
            {
                numb = numb * (x-X[j]);
                denb = denb * (X[i]-X[j]);
            }
        }
        sumab = sumab + (numb/denb)*Y[i];
        contb++;
        numb = 1;
        denb = 1;
    }

    //Orden c

    float sumac=0, numc=1, denc=1, contc=0;
    for(int i=0; i<=c; i++)
    {
        for(int j=0; j<=c; j++)
        {
            if(j!=contc)
            {
                numc = numc * (x-X[j]);
                denc = denc * (X[i]-X[j]);
            }
        }
        sumac = sumac + (numc/denc)*Y[i];
        contc++;
        numc = 1;
        denc = 1;
    }



    printf("\t-------------------------------------------------------------\n");
    printf("\n\tEl polinomio interpolado de orden %.2d, evaluado en %.2f es %.2f\n\n", a, x, sumaa);
    printf("\n\tEl polinomio interpolado de orden %.2d, evaluado en %.2f es %.2f\n\n", b, x, sumab);
    printf("\n\tEl polinomio interpolado de orden %.2d, evaluado en %.2f es %.2f\n\n", c, x, sumac);
    printf("\t-------------------------------------------------------------\n");
    return 0;
}

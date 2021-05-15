#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Cantidad de puntos..." << endl;
    cin >> n;
    cout << endl;

    float x;
    cout << "Introduce el valor de x en el que se evaluara la interpolacion" << endl;
    cin >> x;
    cout << endl;

    int a, b, c;
    cout << "Introduce tres ordenes en los que se evaluara" << endl;
    cin >> a >> b >> c;
    cout << endl;

    float X[n], Y[n];
    cout << "Introduce los pares coordenados separados por un espacio" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    cout << endl;


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



    cout << "\t-------------------------------------------------------------" << endl;
    cout << endl << "\tEl polinomio interpolado de orden " << a << ", evaluado en " << x << " es " << sumaa << endl << endl;
    cout << endl << "\tEl polinomio interpolado de orden " << b << ", evaluado en " << x << " es " << sumab << endl << endl;
    cout << endl << "\tEl polinomio interpolado de orden " << c << ", evaluado en " << x << " es " << sumac << endl << endl;
    cout << "\t-------------------------------------------------------------" << endl;



    return 0;
}

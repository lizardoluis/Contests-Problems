#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950
#define G 10

using namespace std;

double Points(double Rad, short V0, short K1, short K2);
double MaxHeight(double Vy);
double MaxDist(double Vy, double T);
double Tempo(double V);

int main()
{
    short T, V0, K1, K2;

    scanf("%hd", &T);

    for(short i=0; i<T; i++)
    {
        scanf("%hd%hd%hd", &V0, &K1, &K2);

        double L1=0, L2, R2, R1=PI;

        do{
            L2 = (L1*2+R2)/3;
            R2 = (L1+2*R1)/3;
            if( Points(L2, V0, K1, K2) > Points(R2, V0, K1, K2) )
                R1 = R2;
            else
                L1 = L2;

        }while(R1-L1 > 0.0001);

        printf("%.3f %.3f\n", R1, Points(R1, V0, K1, K2));
    }

    return 0;
}

double Points(double Rad, short V0, short K1, short K2)
{
    //printf("\nVx: %f   Vy: %f", V0*cos(Rad), V0*sin(Rad) );
    double Y = MaxHeight( V0*sin(Rad) );
    double X = MaxDist(V0*cos(Rad), Tempo(V0*sin(Rad)) );

    //printf("\nX: %f  Y: %f", X, Y);

    return K1*X + K2*Y;
}

double MaxHeight(double Vy)
{
    return Vy*Vy/(2*G);
}

double MaxDist(double Vy, double T)
{
    return Vy*T;
}

double Tempo(double V)
{
    return 2*(V/G);
}



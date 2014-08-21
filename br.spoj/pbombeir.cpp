#include <stdio.h>
#include <math.h>

typedef struct Ponto{
    double x, y;
} Ponto;

double calcdistancia(Ponto a, Ponto b);
bool isEqual(Ponto a, Ponto b);
double determinante(Ponto a, Ponto b, Ponto c);
bool eq(double a, double b);

using namespace std;

int main()
{
    int n;
    Ponto Exec, Legs, Judi;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &Exec.x, &Exec.y, &Legs.x, &Legs.y, &Judi.x, &Judi.y);

        if( isEqual(Exec,Legs) || isEqual(Exec,Judi) || isEqual(Legs,Judi) )
            printf("There is an infinity of possible locations.\n");
        else if ( eq(determinante(Exec, Legs, Judi), 0) )
            printf("There is no possible location.\n");
        else{

            Ponto A;
            A.x = (Exec.x*Exec.x)+(Exec.y*Exec.y);
            A.y = Exec.y;

            Ponto B;
            B.x = (Legs.x*Legs.x)+(Legs.y*Legs.y);
            B.y = Legs.y;

            Ponto C;
            C.x = (Judi.x*Judi.x)+(Judi.y*Judi.y);
            C.y = Judi.y;

            double h = determinante(A, B, C) / (2*determinante(Exec, Legs, Judi));

            A.y = (Exec.x*Exec.x)+(Exec.y*Exec.y);
            A.x = Exec.x;

            B.y = (Legs.x*Legs.x)+(Legs.y*Legs.y);
            B.x = Legs.x;

            C.y = (Judi.x*Judi.x)+(Judi.y*Judi.y);
            C.x = Judi.x;

            double k = determinante(A, B, C) / (2*determinante(Exec, Legs, Judi));

            printf("The equidistant location is (%.7lf, %.7lf).\n", h, k);
        }

    }


    return 0;
}

double determinante(Ponto a, Ponto b, Ponto c)
{
    return ((a.x * b.y) + (a.y * c.x) + (b.x * c.y) - (c.x * b.y) - (c.y * a.x) - (b.x * a.y));
}

bool isEqual(Ponto a, Ponto b)
{
    if( eq(a.x, b.x) && eq(a.y, b.y) )
        return true;
    else
        return false;
}

bool eq(double a, double b)
{
    if(a>b) return a-b < 1e-10;
    else return b-a < 1e-10;
}

double calcdistancia(Ponto a, Ponto b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}




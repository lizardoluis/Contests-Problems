#include <stdio.h>
#include <stdlib.h>

typedef struct Time {
    int HH, MM, SS, CC;
} Time;

void PrintTime(Time *t);
unsigned int TimeToUnit(Time *t);
void UnitToTime(Time *t, unsigned int unit);

int main()
{
    Time T, Td;
    unsigned int Unit;

    while(scanf("%2d%2d%2d%2d", &T.HH, &T.MM, &T.SS, &T.CC)>0)
    {
        Unit = TimeToUnit(&T);
        UnitToTime(&Td, Unit);

        PrintTime(&Td);
    }

    return 0;
}

void UnitToTime(Time *t, unsigned int unit)
{
    t->CC = unit%100;
    t->SS = (unit/100)%100;
    t->MM = ((unit/100)/100)%100;
    t->HH = ((unit/100)/100)/100;
}

unsigned int TimeToUnit(Time *t)
{
    double Soma = t->CC + t->SS*100 + t->MM*6000 + t->HH*360000;
    return (unsigned int)Soma*125/108;
}

void PrintTime(Time *t)
{
    printf("%.1d%.2d%.2d%.2d\n", t->HH, t->MM, t->SS, t->CC);
}



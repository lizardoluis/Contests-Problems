#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int dia;
    int mes;
    int ano;
    int consumo;
} Data;

int VerificaConsecutivo(Data A, Data B);
int AnoBissesto(int ano);
int ultimodiames(int mes, int ano);

int main()
{
    Data *dt;
    int NumMedicoes;
    int i;
    int NumDias, Consumo;

    fscanf(stdin, "%d", &NumMedicoes);
    while(NumMedicoes > 0)
    {
        dt = (Data *) malloc (NumMedicoes*sizeof(Data));
        NumDias=0;
        Consumo=0;

        for(i=0; i<NumMedicoes; i++)
        {
            fscanf(stdin, "%d %d %d %d", &dt[i].dia, &dt[i].mes, &dt[i].ano, &dt[i].consumo);
        }

        for(i=0; i<NumMedicoes; i++)
        {
            if(VerificaConsecutivo(dt[i], dt[i+1])){
                NumDias++;
                Consumo += dt[i+1].consumo - dt[i].consumo;
            }
        }

        fprintf(stdout, "\n\n%d %d\n", NumDias, Consumo);
        free(dt);
        fscanf(stdin, "%d", &NumMedicoes);

    }
    return 0;
}

int VerificaConsecutivo(Data A, Data B)
{
    if(A.ano == B.ano){
        if(A.mes == B.mes){
            if(B.dia - A.dia == 1){
                return TRUE;
            }
        }
        else{
            if(B.mes - A.mes == 1){
                if(A.dia == ultimodiames(A.mes, A.ano) && B.dia == 1)
                    return TRUE;
            }
        }
    }
    else{
        if(B.ano - A.ano == 1){
            if(A.dia == 31 && A.mes == 12 && B.dia == 1 && B.mes == 1){
                return TRUE;
            }
        }
    }

    return FALSE;
}

int ultimodiames(int mes, int ano)
{
    int diasmes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (AnoBissesto(ano) && mes == 2)
        return 29;
    else
        return diasmes[mes];
}

int AnoBissesto(int ano)
{
    if(ano%4==0 && ano%100!=0)
        return TRUE;
    else
        return FALSE;
}




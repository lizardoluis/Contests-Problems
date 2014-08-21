#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMLETRAS 21

int main()
{
    long ContInstancias = 1;
    int NumAlunos, Menor, i, NumProblemas;
    char Aluno[NUMLETRAS], PiorAluno[NUMLETRAS];

    while( scanf("%d", &NumAlunos)>0 )
    {
        Menor = 11;

        for(i=0; i<NumAlunos; i++)
        {
            scanf("%s %d", Aluno, &NumProblemas);
            if (NumProblemas < Menor){
                strcpy(PiorAluno, Aluno);
                Menor = NumProblemas;
            }
            else if (NumProblemas == Menor){
                if (strcmp(Aluno, PiorAluno) > 0 ){
                    strcpy(PiorAluno, Aluno);
                    Menor = NumProblemas;
                }
            }
        }

        printf("Instancia %ld\n", ContInstancias++);
        printf("%s\n\n", PiorAluno);
    }

    return 0;
}



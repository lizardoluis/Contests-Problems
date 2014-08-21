#include <stdio.h>
#include <stack>
#include <string.h>

#define TAM 48

using namespace std;

void add(stack <long long> & pilha);
void mul(stack <long long> & pilha);

int main()
{
    int n, num;
    char op;

    scanf("%d%*c", &n);

    for(int k=0; k<n; k++)
    {
        int p=0, aux;
        char str[TAM];
        stack <long long> pilha1;
        stack <long long> pilha2;

        fgets(str, TAM, stdin);

        sscanf(str, "%d%n", &num, &aux);
        p+=aux;
        pilha1.push(num);
        pilha2.push(num);

        while( sscanf(str+p, "%c%d%n", &op, &num, &aux) == 2 )
        {
            p+=aux;
            pilha1.push(num);
            pilha2.push(num);
            if(op == '*')
                mul(pilha1);
            else
                add(pilha2);
        }

        while( pilha1.size() > 1 ){
            add(pilha1);
        }
        while( pilha2.size() > 1 ){
            mul(pilha2);
        }

        if(pilha1.top() > pilha2.top())
            printf("The maximum and minimum are %lld and %lld.\n", pilha1.top(), pilha2.top());
        else
            printf("The maximum and minimum are %lld and %lld.\n", pilha2.top(), pilha1.top());
    }

    return 0;
}

void add(stack <long long> & pilha)
{
    long long a, b;
    a = pilha.top();
    pilha.pop();
    b = pilha.top();
    pilha.pop();
    //printf("\nA %lld ", a+b);
    pilha.push(a + b);
}

void mul(stack <long long> & pilha)
{
    long long a, b;
    a = pilha.top();
    pilha.pop();
    b = pilha.top();
    pilha.pop();
    //printf("\nM %lld ", a*b);
    pilha.push(a * b);
}



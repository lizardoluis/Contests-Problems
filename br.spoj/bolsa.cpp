#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    char proposta;
    double valorproposta;

    while(scanf("%d%*c", &n) && n>0)
    {
        double profit=0.0;
        priority_queue <double> vendas;
        priority_queue <double> compras;

        for(int i=0; i<n; i++)
        {
            scanf("%c %lf%*c", &proposta, &valorproposta);

            if(proposta == 'V'){
                if (!compras.empty() && -valorproposta + compras.top() >= 0) {
                    profit += compras.top() - valorproposta;
                    compras.pop();
                }
                else{
                    vendas.push(-valorproposta);
                }
            }
            else{
                if (!vendas.empty() && valorproposta + vendas.top() >= 0) {
                    profit += valorproposta + vendas.top();
                    vendas.pop();
                }
                else{
                    compras.push(valorproposta);
                }
            }
        }
        printf("%.2lf\n", profit);
    }

    return 0;
}



#include <stdio.h>
 
int main(){
    int caixas, pilhas, caixa;
 
    while( scanf( "%d%d", &caixas, &pilhas ) ){
        if( !caixas ){
            return 0;
        }
 
        int qtds[pilhas], i, j, linhaCaixa1, pilhaCaixa1;
 
        for( i = 0; i < pilhas; i++ ){
            scanf( "%d", &qtds[i] );
 
            for( j = 0;  j < qtds[i]; j++ ){
                scanf( "%d", &caixa );
 
                if( caixa == 1 ){
                    linhaCaixa1 = j + 1;
                    pilhaCaixa1 = i;
                }
            }
        }
 
        int cima = qtds[pilhaCaixa1] - linhaCaixa1;
        int esquerda = cima, direita = cima;
 
        for( i = pilhaCaixa1 - 1; i >= 0; i-- ){
            if( qtds[i] >= linhaCaixa1 ){
                esquerda += qtds[i] - linhaCaixa1 + 1;
            } else{
                break;
            }
        }
 
        for( i = pilhaCaixa1 + 1; i < pilhas; i++ ){
            if( qtds[i] >= linhaCaixa1 ){
                direita += qtds[i] - linhaCaixa1 + 1;;
            } else{
                break;
            }
        }
 
        printf( "%d\n", (esquerda > direita ) ? direita : esquerda );
    }
}



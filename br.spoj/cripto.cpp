#include <stdio.h>
#define MAX_TEXTO 10000
#define LETRAS_DICT 128

char texto[MAX_TEXTO];

typedef struct conta {
	char letra;
	int repeticoes;
} Conta;

char letras[LETRAS_DICT]; /*Somente letras do alfabeto se possivel*/

char conversao[LETRAS_DICT];

Conta hash_table[LETRAS_DICT];

int compara(Conta * a, Conta *b) {
	if (a->repeticoes < b->repeticoes) {
		return (1);
	} else if (a->repeticoes > b->repeticoes) {
		return (-1);
	} else {
		if (a->letra < b->letra) {
			return (-1);
		} else {
			return (1);
		}
	}
}

int main(void) {

	int num_letras, num_sequencia;
	int i;

	int num_testes = 0;

	while (scanf("%d %d", &num_letras, &num_sequencia), num_letras
			|| num_sequencia) {

		getchar();

		for (i = 0; i < num_sequencia; i++) {
			letras[i] = getchar();
		}

		getchar();

		for (i = 0; i < LETRAS_DICT; i++) {
			conversao[i] = i;
			hash_table[i].letra = i;
			hash_table[i].repeticoes = 0;
		}

		for (i = 0; i < num_letras; i++) {
			texto[i] = getchar();
			hash_table[texto[i]].repeticoes++;
		}

		getchar();

		hash_table[' '].repeticoes = -1;

		qsort(hash_table, LETRAS_DICT, sizeof(Conta), compara);

		for (i = 0; i < num_sequencia; i++) {
			conversao[hash_table[i].letra] = letras[i];
		}

		num_testes++;
		printf("Teste %d\n", num_testes);
		for (i = 0; i < num_letras; i++) {
			putchar(conversao[texto[i]]);
		}
		printf("\n\n");
	}

	return 0;
}



//#include <stdio.h>
//#include <vector>
//#include <string.h>
//#include <stack>
//#include <algorithm>
//#include <iostream>
//
//#define TAM 100001
//#define TAM_VETOR 30000
//
//using namespace std;
//
//int main()
//{
//    int Instancias;
//    char op;
//
//    ios::sync_with_stdio(false);
//
//    scanf("%d", &Instancias);
//
//    for(int t=1; t<=Instancias; t++)
//    {
//        int pc=0, pio=0, cont=0;
//        char Entrada[TAM], Codigo[TAM];
//
//        vector <char> Vetor(TAM_VETOR, 0);
//        stack <int> Pilha;
//        scanf("%s %s", Entrada, Codigo);
//
//        printf("Instancia %d\n", t);
//
//        for(unsigned ps=0; ps<strlen(Codigo); ps++)
//        {
//            op = Codigo[ps];
//            //printf("\nPS %2d, PC %2d, OP %2c, Pont %3d", ps, pc, op, Vetor[pc]);
//
//            switch(op){
//                case '>':
//                    pc++;
//                    break;
//                case '<':
//                    pc--;
//                    break;
//                case '+':
//                    Vetor[pc]++;
//                    break;
//                case '-':
//                    if(Vetor[pc] == 0)
//                        ps=strlen(Codigo);
//                    Vetor[pc]--;
//                    break;
//                case '.':
//                    if(Vetor[pc] == 0)
//                        ps=strlen(Codigo);
//                    printf("%c", Vetor[pc]);
//                    break;
//                case ',':
//                    if(pio < (int)strlen(Entrada)+1)
//                        Vetor[pc] = Entrada[pio++];
//                    else
//                        Vetor[pc] = 0;
//                    break;
//                case '[':
//                    Pilha.push(ps);
//                    if(Vetor[pc] == 0){
//                        Pilha.pop();
//                        while(true){
//                            ps++;
//                            if(Codigo[ps]=='[')
//                                cont++;
//                            else if(Codigo[ps] == ']'){
//                                if(cont>0)
//                                    cont--;
//                                else{
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    break;
//                case ']':
//                    ps = Pilha.top()-1;
//                    Pilha.pop();
//                    break;
//                case '#':
//                    for(int i=0; i<10; i++)
//                        printf("%c", Vetor[i]);
//                    break;
//                default:
//                    break;
//            }
//        }
//        printf("\n\n");
//    }
//
//    return 0;
//}

#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

char bytes[30000];
int ponteiroCodigo;
int ponteiroEntrada;
int ponteiro;
string out;
string entrada;
string codigo;
stack<int> lastPonteiro;

void executa(char instrucao) {
        if (instrucao == '>') {
                ponteiro++;
        } else if (instrucao == '<') {
                ponteiro--;
        } else if (instrucao == '+') {
                bytes[ponteiro]++;
        } else if (instrucao == '-') {
                bytes[ponteiro]--;
        } else if (instrucao == '.') {
                out += bytes[ponteiro];
        } else if (instrucao == ',') {
                int tam = entrada.size();
                if (ponteiroEntrada < tam) {
                        bytes[ponteiro] = entrada[ponteiroEntrada++];
                } else {
                        bytes[ponteiro] = 0;
                }
        } else if (instrucao == '[') {
                if (bytes[ponteiro] == 0) {
                        int quantos = 1;
                        while (quantos > 0) {
                                char c = codigo[ponteiroCodigo];
                                if (c == ']') {
                                        quantos--;
                                } else if (c == '[') {
                                        quantos++;
                                }
                                ponteiroCodigo++;
                        }
                } else {
                        lastPonteiro.push(ponteiroCodigo - 1);
                }
        } else if (instrucao == ']') {
                if (bytes[ponteiro] == 0) {
                        lastPonteiro.pop();
                } else {
                        ponteiroCodigo = lastPonteiro.top();
                        lastPonteiro.pop();
                }
        } else if (instrucao == '#') {
                for (int i = 0; i < 10; i++) {
                        out += bytes[i];
                }
        }
}

void compila() {
        int tam = codigo.size();
        while (ponteiroCodigo < tam) {
                executa(codigo[ponteiroCodigo++]);
        }
}

int main() {
        int casos;
        cin >> casos;
        for (int c = 1; c <= casos; c++) {
                char in[100000];
                char code[100000];

                while (true) {
                        cin.getline(in, 100000, '\n');
                        if (in[0] != '\0' && in[0] != ' ' && in[0] != '\r' && in[0] != '\n') {
                                break;
                        }
                }
                entrada = in;
                cin.getline(code, 100000, '\n');
                codigo = code;

                if (c > 1) {
                        memset(bytes, 0, sizeof(bytes));
                }

                ponteiro = ponteiroCodigo = ponteiroEntrada = 0;

                out = "";

                compila();

                cout << "Instancia " << c << "\n" << out << "\n\n";
        }

        return 0;
}



#include <stdlib.h>
#include <stdio.h>

#define BARALHO 13

class Monte
{
    private:
        short Topo;
        short NCartas;
        static short MaiorMonte;

    public:
        Monte();
        void insereCarta(short Carta);
        void moveMonte(Monte *S);
        void setTopo(short topo);
        void setNCartas(short ncartas);
        short getTopo();
        short getNCartas();
        static short getMaiorMonte();
        static void setMaiorMonte(short Tam);
};

//-----------------------------------------------------------------

class Descarte
{
    private:
        int Cartas[BARALHO];

    public:
        Descarte();
        void insereCarta(short Carta);
        bool retiraCarta(short Carta);
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

int main()
{
    int N, J, Token, TopoBaralho;
    Monte *Jogador;
    scanf("%d %d", &N, &J);

    while(N!=0 && J!=0)
    {
        Descarte Lixo;
        Jogador = new Monte[J];
        Token=0;
        Monte::setMaiorMonte(0);

        for(int i=0; i<N; i++)
        {
            scanf("%d", &TopoBaralho);
            if( Lixo.retiraCarta(TopoBaralho) ){
                Jogador[Token].insereCarta(TopoBaralho);
                Jogador[Token].insereCarta(TopoBaralho);
            }else{
                bool Check = false;
                for(int j=0; j<J; j++){

                    if( Jogador[j].getTopo()==TopoBaralho && j!=Token ){
                        Jogador[Token].moveMonte( &Jogador[j] );
                        Check = true;
                        break;
                    }
                }
                if(Check==false){
                    if(Jogador[Token].getTopo()==TopoBaralho)
                        Jogador[Token].insereCarta(TopoBaralho);
                    else{
                        Lixo.insereCarta(TopoBaralho);
                        Token = (Token+1)%(J);
                    }
                }
            }
        }
        //Imprimir resultado
        printf("%hd ", Monte::getMaiorMonte());
        for(int i=0; i<J; i++){
            if(Jogador[i].getNCartas() == Monte::getMaiorMonte())
                printf("%d ", i+1);
        }

        printf("\n");
        delete Jogador;
        scanf("%d %d", &N, &J);
    }
    return 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

Monte::Monte(){
    Topo = 0;
    NCartas = 0;
}

short Monte::MaiorMonte = 0;

void Monte::setMaiorMonte(short Tam)
{
    MaiorMonte=Tam;
}

void Monte::setTopo(short topo)
{
    Topo = topo;
}

void Monte::setNCartas(short ncartas)
{
    NCartas = ncartas;
}

short Monte::getMaiorMonte()
{
    return MaiorMonte;
}

void Monte::insereCarta(short Carta)
{
    Topo = Carta;
    NCartas++;
    if(NCartas > getMaiorMonte())
        setMaiorMonte(NCartas);
}

void Monte::moveMonte(Monte *S)
{
    NCartas += S->NCartas+1;
    Topo = S->Topo;
    S->setNCartas(0);
    S->setTopo(0);
    if(NCartas > getMaiorMonte())
        setMaiorMonte(NCartas);
}

short Monte::getTopo()
{
    return Topo;
}

short Monte::getNCartas()
{
    return NCartas;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

Descarte::Descarte()
{
    for(int i=0; i<BARALHO; i++)
    {
        Cartas[i] = 0;
    }
}

void Descarte::insereCarta(short Carta)
{
    Cartas[Carta-1]++;
}

bool Descarte::retiraCarta(short Carta)
{
    if(Cartas[Carta-1] == 1){
        Cartas[Carta-1]--;
        return true;
    }
    else{
        return false;
    }
}



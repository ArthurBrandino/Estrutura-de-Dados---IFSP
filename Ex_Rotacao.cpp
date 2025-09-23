/*Implemente um programa que realize a seguinte tarefa:

    Leia, de uma única vez, cinco números inteiro.
    Insira esses números, na ordem digitada, em uma árvore AVL inicialmente vazia.
    A cada inserção, verifique se houve necessidade de balanceamento da árvore.
    Exiba, na ordem em que ocorrerem, as rotações realizadas para manter a árvore balanceada.

Tipos de rotações a considerar:

    LL – rotação simples à direita
    RR – rotação simples à esquerda
    LR – rotação dupla (esquerda-direita)
    RL – rotação dupla (direita-esquerda)
    Nenhuma – caso a árvore já esteja balanceada

Exemplo de saída esperada:

      RL, LL, RL, LR.*/

#include <iostream>
using namespace std;

struct NoAVL
{
    int chave;
    int fb;
    NoAVL* dir;
    NoAVL* esq;
};

string rotacoes[5];
int contador;

NoAVL* CriarNo(int chave){
    NoAVL* novoNo = new NoAVL;
    novoNo->chave = chave;
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
    novoNo->fb = 0;
    return novoNo;
}

NoAVL* RotacaoL(NoAVL* p){
    NoAVL* u = p->esq;

    if (u->fb == -1)
    {
        /* Rotação LR */
        NoAVL* v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if (v->fb == -1) {
            p->fb = 0;
            u->fb = 1;
        } else if (v->fb == 1) {
            p->fb = -1;
            u->fb = 0;
        }

        v->fb = 0;

        rotacoes[contador] = "LR";
        contador++;
        return v;
    }

    /* Rotação LL */
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    rotacoes[contador] = "LL";
    contador++;
    return u;
}


NoAVL* RotacaoR(NoAVL* p){
    NoAVL* u = p->dir;

    if (u->fb == 1)
    {
        NoAVL* v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->fb == -1) {
            p->fb = 1;
            u->fb = 0;
        } else if (v->fb == 1) {
            p->fb = 0;
            u->fb = -1;
        }

        v->fb = 0;
        rotacoes[contador] = "RL";
        contador++;
        return v;
    }

    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    rotacoes[contador] = "RR";
    contador++;
    return u;
}

NoAVL* Inserir (NoAVL*& raiz, int chave, bool& cresceu){

    if(raiz == nullptr){
        cresceu = true;
        raiz = CriarNo(chave);
    }

    else if(chave < raiz->chave){
        Inserir (raiz->esq, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0;
            else if (raiz->fb == 1)
            {
                raiz = RotacaoL (raiz);
                cresceu = false;
            }
        }
    }
    else {
        Inserir (raiz->dir, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0;
            else if (raiz->fb == -1)
            {
                raiz = RotacaoR (raiz);
                cresceu = false;
            }
        }
    }

    return raiz;
}

int main()
{
    NoAVL* raiz = nullptr;
    int N;

    bool cresceu = false;

    for(int i = 0; i < 5; i++)
    {
        cin >> N;
        Inserir (raiz, N, cresceu);
    }

    for(int i = 0; i < contador; i++)
    {
        cout << rotacoes[i] << " - ";
    }

    return 0;
}

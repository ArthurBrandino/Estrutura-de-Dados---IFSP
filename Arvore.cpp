#include <iostream>
using namespace std;

struct No
{
    int chave;
    No* dir;
    No* esq;
};

// ========================
// Fila manual
// ========================
const int MAX = 100; // tamanho máximo da fila
No* fila[MAX];
int ini = 0, fim = 0;

bool FilaVazia()
{
    return ini == fim;
}

bool FilaCheia()
{
    return (fim + 1) % MAX == ini;
}

void Enfileirar(No* n)
{
    if (!FilaCheia())
    {
        fila[fim] = n;
        fim = (fim + 1) % MAX;
    }
}

No* Desenfileirar()
{
    if (!FilaVazia())
    {
        No* n = fila[ini];
        ini = (ini + 1) % MAX;
        return n;
    }
    return nullptr;
}

// ========================
// Árvore Binária
// ========================
void Inserir(int chave, No*& raiz)
{
    if (raiz == nullptr)
    {
        raiz = new No;
        raiz->chave = chave;
        raiz->dir = nullptr;
        raiz->esq = nullptr;
    }
    else if (chave < raiz->chave)
        Inserir(chave, raiz->esq);
    else
        Inserir(chave, raiz->dir);
}

bool Busca(int pesq, No* raiz)
{
    if (raiz == nullptr)
        return false;
    else if (pesq == raiz->chave)
        return true;
    else if (pesq < raiz->chave)
        return Busca(pesq, raiz->esq);
    else
        return Busca(pesq, raiz->dir);
}

int Contagem(No* raiz)
{
    if (raiz == nullptr)
        return 0;
    else
        return Contagem(raiz->esq) + 1 + Contagem(raiz->dir);
}

void EmOrdem(No* raiz)
{
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave << " - ";
        EmOrdem(raiz->dir);
    }
}

void PreOrdem(No* raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->chave << " - ";
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

void PosOrdem(No* raiz)
{
    if (raiz != nullptr)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        cout << raiz->chave << " - ";
    }
}

void Largura(No* raiz)
{
    if (raiz == nullptr) return;

    // reinicia fila
    ini = fim = 0;
    Enfileirar(raiz);

    while (!FilaVazia())
    {
        No* atual = Desenfileirar();
        cout << atual->chave << " - ";

        if (atual->esq != nullptr)
            Enfileirar(atual->esq);
        if (atual->dir != nullptr)
            Enfileirar(atual->dir);
    }
}

void Remover(No*& raiz, int chave)
{
    if(raiz == nullptr)
    {
        cout << "Valor nao encontrado!" << endl;
        return;
    }
    if (chave < raiz->chave)
        Remover(raiz->esq, chave);
    else if (chave > raiz->chave)
        Remover(raiz->dir, chave);
    else
        if(raiz->dir == nullptr && raiz->esq == nullptr)
        {
            delete raiz;
        }
    else if (raiz->esq == nullptr)
        {
            raiz = raiz->dir;
        }
    else if (raiz->dir == nullptr)
        {
            raiz = raiz->esq;
        }
    else
    {
        No* sucessor = raiz->dir;
        while(sucessor->esq != nullptr)
        {
            sucessor = sucessor->esq;
        }
        raiz->chave = sucessor->chave;
        Remover(raiz->dir, sucessor->chave);


    }
}

void RemoverIterativo(No*& raiz, int chave)
{

    No* atual = raiz;
    No* pai = nullptr;

    while(atual != nullptr && atual->chave != chave)
    {
        pai = atual;
        if(chave < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if(atual == nullptr)
    {
        cout << "Valor nao encontrado!" << endl;
        return;
    }


    if(atual->esq == nullptr && atual->dir == nullptr)
    {
        if(pai == nullptr)
            raiz = nullptr;
        else if(pai->esq == atual)
            pai->esq = nullptr;
        else
            pai->dir = nullptr;

        delete atual;
    }
    else if(atual->esq == nullptr || atual->dir == nullptr)
    {
        No* filho = (atual->esq != nullptr) ? atual->esq : atual->dir;

        if (pai == nullptr) 
            raiz = filho;
        else if (pai->esq == atual)
            pai->esq = filho;
        else
            pai->dir = filho;

        delete atual;
    }
  
    else {
      
        No* sucessorPai = atual;
        No* sucessor = atual->dir;

        while (sucessor->esq != nullptr) {
            sucessorPai = sucessor;
            sucessor = sucessor->esq;
        }

        atual->chave = sucessor->chave;

        if (sucessorPai->esq == sucessor)
            sucessorPai->esq = sucessor->dir;
        else
            sucessorPai->dir = sucessor->dir;

        delete sucessor;
    }
    delete raiz;
}

// ========================
// Programa principal
// ========================
int main()
{
    No* raiz = nullptr;
    int pesq;

    Inserir(4, raiz);
    Inserir(3, raiz);
    Inserir(5, raiz);
    Inserir(2, raiz);
    Inserir(7, raiz);

    cout << "Digite um numero para buscar: ";
    cin >> pesq;

    if (Busca(pesq, raiz))
        cout << "Encontrou" << endl;
    else
        cout << "Nao Encontrou" << endl;

    cout << "Total de nos: " << Contagem(raiz) << endl;

    cout << "Em Ordem: ";
    EmOrdem(raiz);
    cout << endl;

    cout << "Pre Ordem: ";
    PreOrdem(raiz);
    cout << endl;

    cout << "Pos Ordem: ";
    PosOrdem(raiz);
    cout << endl;

    cout << "Largura: ";
    Largura(raiz);
    cout << endl;

    return 0;
}


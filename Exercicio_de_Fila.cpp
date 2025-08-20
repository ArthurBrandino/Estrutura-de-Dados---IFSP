#include <iostream>

using namespace std;

int fila[4];
int inicio = 0, fim = 0;

void Enfileirar(int valor){
    if( fim == 4)
    {
        cout << "Fila cheia!" << endl;
        return;
    }
    fila[fim] = valor;
    fim++;
}

void Exibir (){
    for(int i = inicio; i < fim; i++)
    {
        cout << fila[i] << " ";
    }
}

void Desenfileirar(){
    if(fim == inicio)
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    fila[inicio] = 0;
    inicio++;
}

int main()
{
    Enfileirar(3);
    Enfileirar(5);
    Enfileirar(4);
    Enfileirar(9);
    Exibir();
    Enfileirar(9);
    Desenfileirar();
    Desenfileirar();
    Exibir();
    return 0;
}

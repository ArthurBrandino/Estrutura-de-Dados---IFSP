#include <iostream>

using namespace std;

void mostrarVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++)
    { 
        cout << vetor[i];
        if(i + 1 != tamanho)
            cout << " - "; 
    }
    cout << endl;
}

void bubbleSort(int vetor[], int tamanho)
{
    bool trocou;
    for(int j = 0; j < tamanho - 1; j++)
    {
        trocou = false;
        for(int i = 0; i < tamanho -1 - j; i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                int auxiliar = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = auxiliar;
                trocou =
                 true;
            }
        }
        if(trocou)
            break;
    }
}

void selectionSort(int vetor[], int tamanho)
{
    for(int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if(vetor[j] < vetor[menor])
                menor = j;
        }

        if(menor != i)
        {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux; 
        }
    }
}

/*void insertionSort(int vetor[], int tamanho)
{
    for(int i = 1; i < tamanho; i++)
    {
        int cont = i -1;
        while (cont >= 0 )
        {
            if(vetor[cont] > vetor[i])
            {
                vetor[cont + 1] = vetor[cont];
            }

            cont--;
        }
        
    }
}*/

int main()
{
    int vetor[] = {5,2,8,1,9,7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    mostrarVetor(vetor, tamanho);
    selectionSort(vetor, tamanho);
    mostrarVetor(vetor, tamanho);

    return 0;
}

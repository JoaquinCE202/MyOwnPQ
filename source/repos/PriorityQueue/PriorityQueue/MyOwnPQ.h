
#include <iostream>
#include<tuple>
#include <math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;


template <typename ElemType>
class MyOwnPriorityQueue
{
public:

    MyOwnPriorityQueue();
    ~MyOwnPriorityQueue();
    void insert(int prioridad, ElemType valor);
    void pop();
    void Print();
    ElemType front();
    bool find(ElemType valor);
    void verificar_espacio();
    void propagar_cambios_abajo(int indice);
    void propagar_cambios_arriba(int indice);

private:
    int tamanho = 30;
    tuple<int, ElemType>* tree;
    int tamanho_ocupado;
};

template <typename ElemType>
MyOwnPriorityQueue<ElemType>::MyOwnPriorityQueue() {
    tamanho_ocupado = 0;
    tree = new tuple<int, ElemType>[tamanho];
    for (int x = 0; x < tamanho; x++)
    {
        get<0>(tree[x]) = -1;
    }
}

template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::verificar_espacio() {
    if (tamanho_ocupado == tamanho)
    {
        tuple <int, ElemType>* aux;
        aux = new tuple <int, ElemType>[tamanho];
        for (int x = 0; x < tamanho; x++)
        {
            aux[x] = tree[x];
        }
        int prev = tamanho;
        tamanho = tamanho * 2;
        tree = new tuple <int, ElemType>[tamanho];
        for (int x = 0; x < prev; x++)
        {
            tree[x] = aux[x];
        }
        for (int x = prev; x < tamanho; x++)
        {
            get<0>(tree[x]) = -1;
        }
    }
    else
    {
        return;
    }
}

template <typename ElemType>
bool MyOwnPriorityQueue<ElemType>::find(ElemType valor)
{
    for (int x = 0; x < tamanho_ocupado; x++)
    {
        if (valor == get<1>(tree[x]))
        {
            return true;
        }
    }
    return false;
}


template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::insert(int prioridad, ElemType valor) {
    tuple <int, ElemType> elemento;
    get<0>(elemento) = prioridad;
    get<1>(elemento) = valor;
    verificar_espacio();
    if (find(valor,prioridad))
    {
        return;
    }

    if (tamanho_ocupado == 0)
    {
        tree[0] = elemento;

    }
    else
    {
        tree[tamanho_ocupado] = elemento;
        propagar_cambios_arriba(tamanho_ocupado+1);
    }
    tamanho_ocupado++;
}

template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::propagar_cambios_arriba(int indice)
{
    tuple <int, ElemType> aux;
    if (indice == 1)
    {
        return;
    }
    else
    {
        if (get<0>(tree[indice - 1]) < get<0>(tree[(indice / 2) - 1]))
        {
            aux = tree[indice - 1];
            tree[indice - 1] = tree[(indice / 2) - 1];
            tree[(indice / 2) - 1] = aux;
            propagar_cambios_arriba(indice / 2);
        }
        else
        {
            return;
        }
    }
}


template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::propagar_cambios_abajo(int indice)
{
    tuple <int, ElemType> aux;
    int minimo;
    if (indice > tamanho)
    {
        return;
    }
    if (get<0>(tree[indice - 1]) == -1)
    {
        return;
    }
    else
    {
        if ((indice * 2) - 1 < tamanho && get<0>(tree[(indice * 2) - 1]) != -1)
        {
            if (get<0>(tree[(indice * 2 + 1) - 1])==-1 || get<0>(tree[(indice * 2) - 1]) < get<0>(tree[(indice * 2 + 1) - 1]))
            {
                minimo = (indice * 2) - 1;
            }
            else
            {
                minimo = (indice * 2 + 1) - 1;
            }
            if (get<0>(tree[indice - 1]) > get<0>(tree[minimo]))
            {
                aux = tree[indice - 1];
                tree[indice - 1] = tree[minimo];
                tree[minimo] = aux;
                propagar_cambios_abajo(minimo + 1);
                }
            else
            {
                return;
            }
            
        }
        else
        {
            return;
        }

    }
}
template <typename ElemType>
MyOwnPriorityQueue<ElemType>::~MyOwnPriorityQueue()
{
    delete[] tree;
}

template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::pop()
{
    tuple <int, ElemType> aux;
    if (tamanho_ocupado == 0)
    {
        get<0>(tree[0]) = -1;
    }
    else
    {
        aux = tree[0];
        tree[0] = tree[tamanho_ocupado - 1];
        tree[tamanho_ocupado - 1] = aux;
        get<0>(tree[tamanho_ocupado - 1]) = -1;
        propagar_cambios_abajo(1);
        tamanho_ocupado--;
    }
}

template <typename ElemType>
ElemType MyOwnPriorityQueue<ElemType>::front()
{
    return get<1>(tree[0]);
}




template <typename ElemType>
void MyOwnPriorityQueue<ElemType>::Print()
{
    cout << "prioridad: ";
    for (int x = 0; x < tamanho; x++)
    {
        if (get<0>(tree[x]) != -1)
        {
            cout << get<0>(tree[x]) << " ";
        }

    }
    cout << endl;
    cout << "valor: ";
    for (int x = 0; x < tamanho; x++)
    {
        if (get<0>(tree[x]) != -1)
        {
            cout << get<1>(tree[x]) << " ";
        }

    }
    cout << endl;
}



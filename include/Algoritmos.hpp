#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "../include/Dados.hpp"

#include<string>
#include<iostream>

using namespace std;

class Algoritmos
{        
    public: 
        //Funções Base ==

        //Realiza a troca de posições dado um objeto de classe
        void Troca(char TipoTroca, Dados *&d, int i, int j);
        //Realiza a troca de posições dado um objeto de classe
        //baseado no endereço de memória
        void Troca(string* a, string* b);

        //Algoritmos de Ondernação ==

        //MergeSort Functions
        //Método que faz a ordenação por meio do MergeSort
        void MergeSort(Dados *&d, int low, int high);
        //Função que une ambos os lados ordenados após concluída ordenação
        void Merge(Dados *&d, int low, int high, int mid);
        
        //HeapSort Functions
        //Método para ordenação de dados por meio do QuickSort
        void HeapSort(Dados*& d, int n);
        //Método auxiliar para criação de um Heap para os dados
        void Heap(Dados *&d, int n, int i);

        //QuickSort Functions
        //Método para ordenação de dados por meio do QuickSort
        void QuickSort(Dados *&d, int low, int high);
        // Método auxiliar para separação do array
        int Split (Dados *&d, int low, int high);

        //RadixSort Functions
        //Método para ordenação de dados por meio do RadixSort  
        void RadixSort(Dados *&d, int n);
        //Método auxiliar para realizar a contagem e retorno ao método RadixSort
        void CountSort(Dados *&d, int n, int exp);        
};
#endif
#include "../include/Algoritmos.hpp"
#include "../include/Arquivo.hpp"
#include "../include/Dados.hpp"

#include <string>
#include <iostream>

using namespace std;

#pragma region MergeSort

void Algoritmos::Merge(Dados *&d, int left, int mid, int right)
{
    auto const subA1 = mid - left + 1;
    auto const subA2 = right - mid;
 
    // Cria arrays temporários
    auto *Lesquerdo = new string[subA1],
         *Ldireito = new string[subA2];
 
    // Copia os dados para os array 
    // do lado direito e do lado esquerdo
    for (auto i = 0; i < subA1; i++)
        Lesquerdo[i] = d->getNome(left + i);
    for (auto j = 0; j < subA2; j++)
        Ldireito[j] = d->getNome(mid + 1 + j);

    // Endereço inicial do subarray 1
    // Endereço inicial do subarray 2
    // Endereço inicial do array de união
    auto indexA1 = 0, indexA2 = 0; 
    int indexMerge = left; 
 
    // Faz a junção dos arrays esquerdo e direito
    // em um array[Esquerda..Direita]
    while (indexA1 < subA1 && indexA2 < subA2) {
        if (Lesquerdo[indexA1] <= Ldireito[indexA2]) {
            d->setNome(indexMerge, Lesquerdo[indexA1]);
            indexA1++;
        }
        else {
            d->setNome(indexMerge, Ldireito[indexA2]);
            indexA2++;
        }
        indexMerge++;
    }
    // Copia os elementos restantes do array
    // Esquerda[], cso tenha algum
    while (indexA1 < subA1) {
        d->setNome(indexMerge, Lesquerdo[indexA1]);
        indexA1++;
        indexMerge++;
    }
    // Copia os elementos restantes do array
    // Direita[], cso tenha algum
    while (indexA2 < subA2) {
        d->setNome(indexMerge, Ldireito[indexA2]);
        indexA2++;
        indexMerge++;
    }
}
 
// Inicia do começo ao fim do array, ou seja, 
// inicia pelo lado esquerda[0] e finaliza pelo lado direito[tamanho do array]
void Algoritmos::MergeSort(Dados *&d, int const begin, int const end)
{
    if (begin >= end)
        return; // Retorna recursivamente
 
    auto mid = begin + (end - begin) / 2;
    MergeSort(d, begin, mid);
    MergeSort(d, mid + 1, end);
    Merge(d, begin, mid, end);
}

#pragma endregion

#pragma region QuickSort

void Algoritmos::Troca(char TipoTroca, Dados *&d, int i, int j) 
{
  string temp = "";
  int temp_i = 0;

  if(TipoTroca == 'N'){
    temp = d->getNome(i);
    d->setNome(i, d->getNome(j)); 
    d->setNome(j, temp);
  }
  else
  {
    if(TipoTroca == 'D')
    {
      temp_i = d->getDado(i);
      d->setDado(i, d->getDado(j)); 
      d->setDado(j, temp_i);
    }
  }  
}

void Algoritmos::Troca(string* a, string* b) 
{ 
  string t = *a; 
  *a = *b; 
  *b = t; 
} 

void Algoritmos::QuickSort(Dados *&d, int low, int high) 
{ 
    if (low < high) 
    { 
      //Pega a posição correta da partição
      int pi = Split(d, low, high);

      // Separação de elemtos antes e depois da partição        
      QuickSort(d, low, pi - 1); 
      QuickSort(d, pi + 1, high); 
    } 
}

int Algoritmos::Split(Dados *&d, int low, int high) 
{ 
    string pivo = d->getNome(high);
    int i = (low - 1); // Endereço do menor elemento
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // Se o elemento autal for menor que o pivô...
        if (d->getNome(j) < pivo) 
        {           
          i++; // Avança posição
          Troca('N', d, i, j);            
        } 
    } 
    Troca('N', d, i+1, high);
    return (i + 1); 
} 

#pragma endregion

#pragma region HeapSort

void Algoritmos::Heap(Dados*&d, int n, int i)
{
  // Inicialização
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
     
    // se a posição da esquerda for maior que a base
    if (l < n && d->getDado(l) > d->getDado(largest))
        largest = l;
 
    // se a posição da direitoa for a maior até então
    if (r < n && d->getDado(r) > d->getDado(largest))
        largest = r;
 
    // ajuste de maior elemento
    if (largest != i) {
        Troca('D', d, i, largest);
 
        // Heap Recursivo
        Heap(d, n, largest);
    }
}
 
void Algoritmos::HeapSort(Dados*& d, int n)
{
    // Cria o Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap(d, n, i);
 
    // Retirar 1 elemento por vez do Heap
    for (int i = n - 1; i > 0; i--) {
        // Move elemento atual para o fim
        Troca('D', d, 0, i);
         
        // chama o máximo elmento em Heap() 
        // no heap de dados reduzidos
        Heap(d, i, 0);
    }
}

#pragma endregion

#pragma region Radix Sort
 
// Funcao Auxiliar para pegar o maior elemento
int getMax(Dados *&d, int n)
{    
    int mx = d->getDado(0);
    for (int i = 1; i < n; i++)
        if (d->getDado(i) > mx)
            mx = d->getDado(i);
    return mx;
}
 
void Algoritmos::CountSort(Dados *&d, int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
     
    // Marca a contagem dos elementos no array count
    for (i = 0; i < n; i++)
        count[(d->getDado(i) / exp) % 10]++;

    // Muda count[i] para que count[i] contenha
    // o valor atual deste digito na input[i]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Constrói um array de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[(d->getDado(i) / exp) % 10] - 1] = d->getDado(i);
        count[(d->getDado(i) / exp) % 10]--;
    }
 
    // Finalizando processo
    int ax  = -1;

    for (i = 0; i < n; i++)      
      ax = output[i];
      d->setDado(i, ax);
} 
 
void Algoritmos::RadixSort(Dados *&d, int n)
{
    // Acha o maior número dentro os conhecidos
    int m = getMax(d, n); 

    // Faz a contagem para cada dígito
    // exp totaliza 10^i onde "i" é o dígito atual
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(d, n, exp);
}

#pragma endregion

#pragma region Implementações Não Utilizadas

// MergeSort =====================================================================================================
/*
void Algoritmos::MergeSortA(Dados *&d, int low, int high) {
  int mid = 0;  

  if (low < high) {
    mid = ((low + high) / 2);
    MergeSortA(d, low, mid);
    MergeSortA(d, mid + 1, high);
    MergeA(d, low, mid, high);
  }    
}
*/

/*
void Algoritmos::MergeA(Dados *&d, int low, int mid, int high) {
  int i = low, j = mid + 1, k = low;
  int ax = d -> getNumReg() + 1;

  int n1 = mid-low+1;
  int n2 = high - mid;

  string Temp[ax];
  string TempLeft[n1];
  string TempoRigth[n2];

  for(int a =0; a<=mid; ++a)
    TempLeft[a] = d -> getNome(a);

  for (int b = (mid+1); b <= high; ++b)
    TempoRigth[b] = d->getNome(b);
  

  while (i <= mid && j <= high) {
    if ( tolower(d -> getChaveNome(i)) <= tolower(d -> getChaveNome(j)) ) {
      //cout << "Dado: " << d->getNome(i) << endl;
      Temp[k].assign(d -> getNome(i));
      i++;
    } else {
      //cout << "Dado: " << d->getNome(j) << endl;
      Temp[k].assign(d -> getNome(j));
      j++;
    }
    k++;
  }

  if (i > mid) {
    for (int h = j; h <= high; h++) {
      Temp[k].assign(d -> getNome(h));
      k++;
    }
  } 
  else{
    for (int h = i; h <= mid; h++) {
      Temp[k].assign(d -> getNome(h));
      k++;
    }
  }

  for (int i = low; i <= high; i++) //copy from low to high
  {
    d -> setNome(i, Temp[i]);
  }
  
  //Teste
  //cout << endl << endl;
  //for (int i = 0; i < d -> getNumReg(); i++) {
    //cout << "TEmp: " << Temp[i] << endl;
  //}
  //cout << endl << endl;
}
*/

//QuickSort ===========================================================================================================
/*
void Algoritmos::Swap(char TipoTroca, Dados *&d, int i, int j) {
  /*  
    cout << "Chamou troca: " << endl << endl;
    cout << "Posicao: " << i << "  troca com  " << j << endl;
    cout << "Valor 1: " << d->getNome(i) << "  troca com  " << d->getNome(j) << endl << endl;
  
 
  string temp = "";

  if(TipoTroca == 'N'){
    temp = d->getNome(i);
    d->setNome(i, d->getNome(j)); 
    d->setNome(j, temp);
  }
  else{
    temp = d->getDado(i);
    d->setDado(i, d->getDado(j)); 
    d->setDado(j, temp);
  }  

}

void Algoritmos::QuickSort(Dados *&d, int start, int end) 
{
  // index for the "left-to-right scan"
  int i = start;
  // index for the "right-to-left scan"
  int j = end;

  // only examine arrays of 2 or more elements.
  if (j - i >= 1) {
    // The pivot point of the sort method is arbitrarily set to the first element int the array.
    string pivot = d->getNome(i);
    // only scan between the two indexes, until they meet.
    while (j > i) {
     
      string ax = d->getNome(i);
      while (ax[0] <= pivot[i] && i < end && j > i) {
        i++;
      }
      
      string yx = d->getNome(j);
      while (yx[0] >= pivot[0] && j > start && j >= i) {
        j--;
      }
      // check the two elements in the center, the last comparison before the scans cross.
      if (j > i)
        Swap('N', d, i, j);
    }    
    // Swap the pivot point with the last element of the left partition.
    Swap('N', d, start, j);
    //Sort no lado direito
    QuickSort(d, start, j - 1);
    //Sort no lado direito
    QuickSort(d, j + 1, end);    
  }
}
*/


// HeapSort =========================================================
/*
void Algoritmos::Heapify(Dados *d, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && d->getDado(l) > d->getDado(largest))
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && d->getDado(r) > d->getDado(largest))
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        Troca('D', d, i, largest);
  
        // Recursively heapify the affected sub-tree
        Heapify(d, n, largest);
    }
}
  
// main function to do heap sort
void Algoritmos::HeapSort(Dados *d, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(d, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        Troca('D', d, 0, i);
  
        // call max heapify on the reduced heap
        Heapify(d, i, 0);
    }
}
*/


#pragma endregion

// !__Algoritmos
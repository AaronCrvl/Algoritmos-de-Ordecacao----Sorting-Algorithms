#include "../include/Arquivo.hpp"
#include "../include/Algoritmos.hpp"

#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std;

#pragma region Inicialização

void Arquivo::Inicializa()
{  
  string f = "";
  //cout << "Entre com o nome do arquivo: " << endl;
  //cin >> f;
  f = "homologacao.txt";
  this->arquivo = f;

  int c = 0;
  cout << endl;
  cout << "Qual configuração será usada? " << endl;
  cout << "1 - QuickSort x HeapSort" << endl;
  cout << "2 - QuickSort x Radix Exchange Sort" << endl;
  cout << "3 - MergeSort x HeapSort" << endl;
  cout << "4 - MergSort x Radix Sort" << endl;
  cin >> c;
  this->configuracao = c;

  int l = 0;
  cout << "Insira o número de linhas para leitura: " << endl;
  cin >> l;
  cout << endl;
  this->linhasparaleitura = l;  
}

void Arquivo::rodaConfiguracao() 
{           
    Algoritmos a;
        
    if(this->configuracao == 1)
      a.QuickSort(d, 0, d->getNumReg());
      a.HeapSort(d, d->getNumReg());
        
    if(this->configuracao == 2)
      a.QuickSort(d, 0, d->getNumReg());
      a.RadixSort(d, d->getNumReg());

    if(this->configuracao == 3)
      a.HeapSort(d, d->getNumReg());
      a.MergeSort(d, 0, d->getNumReg());
      
    if(this->configuracao == 4)
    {
      a.RadixSort(d, d->getNumReg()); 
      a.MergeSort(d, 0, d->getNumReg());      
    } 
    else
    {
      cout << "Configuração Inválida" << endl;  
      exit;  
    }      
}

#pragma endregion

#pragma region Leitura de Dados

void Arquivo::leArquivo() 
{ 
  try
  {     
    int linhas = 0;
    fstream leitor;
    string temp = "";
    int temp_i =0;
        
    //Cria separador para leitura
    bool divisa = false, adnome = false, addado = false;
    leitor.open(this->arquivo /*"homologacao.txt"*/, ios:: in);

    //Inicia leitura.
    while (getline(leitor, container)) {
      //Monitoramento de linhas lidas               

      if( linhas != linhasparaleitura )
      {
        temp.clear();

        for (int i = 0; i < container.size(); ++i) 
        {
          if (container[i] != ' ' && container[i] != '1' && container[i] != '0') 
          {
            temp += container[i];
          }

          if (container[i] == ' ') 
          {
            divisa = true;        
            nomeTemp = temp;
            adnome = true;
            temp.clear();
          } 
          else 
          {
            if (divisa) {
              int ax = i;
              addado = true;

              while (ax < container.size()) {
                temp += container[ax];
                ++ax;                
              }  

              dadoTemp = stoi(temp);
              divisa = false;
              temp.clear();
              break;
            }
          }
          
          //Atribuição de dados
          if (adnome == true && addado == true) 
          {            
            d -> AdicionaRegistro();
            d -> setDado(d -> getNumReg(), dadoTemp);
            d -> setNome(d -> getNumReg(), nomeTemp);
            char ax = nomeTemp[0];
            d -> setChaveNome(ax);
            adnome = false;
            addado = false;
          } else {}
        }   
        ++linhas;   
      }
      else
        { break; }
    }
      
    cout << endl << endl;    
    rodaConfiguracao();        
    //
    cout << "Resultados: "  << endl << endl;
    d->Imprime();
    d->~Dados();
    delete d;    
  }
  catch(exception e)
  {
    throw e;
  }
}

#pragma endregion

// !__Arquivo(Arq)


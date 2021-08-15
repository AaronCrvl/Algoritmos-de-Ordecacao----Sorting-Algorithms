#include "../include/Arquivo.hpp"
#include "../include/Dados.hpp"
#include "../include/Algoritmos.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// cd TP2_ESTRT\tp\src
// g++ Main.cpp Algoritmos.cpp Dados.cpp Arquivo.cpp -o t

void relogio(){  for (int i=0; i<10; i++){} }

int main()
{
    time_t inicio, fim;

    Arquivo a;
    a.Inicializa();

    // Processos de Tempo ===================================================
    //============= Inicia o relogio =============
    time(&inicio);

    //Leitura do Arquivo =================
    a.leArquivo();
    //Leitura do Arquivo =================
    
    cout << endl;  
    // 
    ios_base::sync_with_stdio(false);  
    relogio();
  
    // Fecha o relógio
    time(&fim);
  
    // Exibição de resultados do relógio: 
    double temp_e = double(fim - inicio);
    cout 
    << "!_Tempo de execucao: " 
    << fixed
    << temp_e 
    << setprecision(5);    
    cout << " sec " << endl;

    //Configuração Utilizada
    cout 
    << "!_Configuracao Escolhida: " 
    <<  a.GetConf()
    << endl;

    //Número de Linhas lidas
    cout 
    << "!_Linhas lidas: " 
    <<  a.GetNLinhas()
    << endl;

    return 0;
}
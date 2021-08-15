#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../include/Dados.hpp"

#include<string>
#include<iostream>

using namespace std;

class Arquivo
{                    
    public:        
        //Inicializa classe com nome do arquivo.
        Arquivo(){}
        //Destrutor
        ~Arquivo(){}   
        //
        int GetConf(){ return this->configuracao; }             
        //
        int GetNLinhas(){ return this->linhasparaleitura; }     
        // Lê o arquivo            
        void leArquivo();        
        //Inicializa as variáveis
        void Inicializa();
        //Roda configuração de Entrada
        void rodaConfiguracao();    

    private: 
        string arquivo = "";
        int configuracao = -1;
        int linhasparaleitura = 0;  
        //     
        Dados *d = new Dados();                 
        string container = "";
        int dadoTemp = 0;
        string nomeTemp = "";                  
};
#endif
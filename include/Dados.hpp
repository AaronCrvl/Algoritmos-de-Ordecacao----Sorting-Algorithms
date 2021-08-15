#ifndef DADOS_H
#define DADOS_H

#include <string>

using namespace std;

class Dados
{    
    public:    
        //Construtor da classe    
        Dados(){}
        //Destrutor da classe
        ~Dados(){}      
        //Retorna o NOME dada uma psoiçãoa    
        string getNome(int pos);       
        //Retorna o DADO dada uma psoiçãoa    
        int getDado(int pos);
        //Retorna o a chave do NOME dada uma psoiçãoa    
        char getChaveNome(char pos);
        //Retorna todo o array de NOME por referência
        string *getAllNome();
        //Retorna todo o array de DADO por referência
        int *getAllDado();
        //Atribuição de valor ao array de NOME dada uma posição
        void setNome(int pos, string n);
        //Atribuição de valor ao array de DADO dada uma posição
        void setDado(int pos, int d);
        //Atribuição de valor ao array de chaves de NOME dada uma posição
        void setChaveNome(char pos);
        //Retorna o número de registros contidos na classe
        // 1 linha de nome e dados = 1 registro
        int getNumReg();        
        //Adiciona +1 a contagem de registros
        void AdicionaRegistro(); 
        //Imprime os arrays de NOME e DADO por completo
        void Imprime();           
        
    private:        
        int NumeroRegistros = -1;
        //
        char ChaveNome[200001]; //200.001 
        string Nome[200001]; //200.001
        int Dado[200001];  //200.001
};
#endif
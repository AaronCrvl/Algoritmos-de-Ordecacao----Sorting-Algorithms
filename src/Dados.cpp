#include "../include/Dados.hpp"

#include <string>
#include <iostream>
 
using namespace std;

#pragma region Gets & Sets

string Dados::getNome(int pos)
{
    return this->Nome[pos];
}

int Dados::getDado(int pos)
{
    return this->Dado[pos];
}

char Dados::getChaveNome(char pos)
{
    return this->ChaveNome[pos];
}

string* Dados::getAllNome()
{
    return this->Nome;
}

int *Dados::getAllDado()
{
    return this->Dado;
}

void Dados::setNome(int pos, string n)
{
    this->Nome[pos] = n;
}

void Dados::setDado(int pos, int d)
{
    this->Dado[pos] = d;
}

void Dados::setChaveNome(char pos)
{
    this->ChaveNome[getNumReg()] = pos;
}

int Dados::getNumReg()
{
    return this->NumeroRegistros;
}

#pragma endregion

#pragma region Métodos

void Dados::AdicionaRegistro()
{
    this->NumeroRegistros += 1;
}

void Dados::Imprime()
{
    for (int i = 0; i <= this->NumeroRegistros; i++)
    {
        cout << /*"Nome: " <<*/ this->Nome[i] << "\t";
        cout << /*"Dado: " <<*/ this->Dado[i] << endl;        
    }    
}

#pragma endregion

// !__Dados
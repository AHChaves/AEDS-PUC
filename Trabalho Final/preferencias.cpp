#include "preferencias.h"

void Preferencias::AddNomes(string nome){
    this->nomeDados.push_back(nome);
}

void Preferencias::AddValores(float valor){
    this->valores.push_back(valor);
}
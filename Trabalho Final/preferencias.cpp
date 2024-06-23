#include "./headers/preferencias.h"

int Preferencias::SizeofNomes(){
    return this->nomeDados.size();
}

string Preferencias::GetNameAt(int i){
    return this->nomeDados.at(i);
}

vector<float> Preferencias::GetValuesAt(int i){
    return this->valores.at(i);
}

void Preferencias::AddNomes(string nome){
    this->nomeDados.push_back(nome);
}

void Preferencias::AddValores(vector<float> vector, float valor){
    vector.push_back(valor);
}
#include <iostream>
#include "./headers/preferencias.h"

void Preferencias::AddNomes(string nome){
    this->nomeDados.push_back(nome);
}

void Preferencias::AddValores(vector<float> vector, float valor){
    vector.push_back(valor);
}

void Preferencias::PrintValues(){

    for(int i =0; i < SizeofNomes(); i++){
        cout << this->nomeDados.at(i);
        for(int j = 0; j < SizeofValores(GetValuesAt(i)); j++){
            cout << this->valores.at(i).at(j);
        }
    }
}

string Preferencias::GetNameAt(int i){
    return this->nomeDados.at(i);
}

vector<float> Preferencias::GetValuesAt(int i){
    return this->valores.at(i);
}

int Preferencias::SizeofNomes(){
    return this->nomeDados.size();
}

int Preferencias::SizeofValores(vector<float> vetor){
    return vetor.size();
}
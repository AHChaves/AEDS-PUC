#include <iostream>
#include "./headers/preferencias.h"

void Preferencias::AddNomes(string nome){
    this->nomeDados.push_back(nome);
}

void Preferencias::AddValues(int i, float value){

    if(i >= this->values.size()){
        vector<float> v1;
        v1.push_back(value);
        this->values.push_back(v1);
    }
    else{
        this->values[i].push_back(value);
    }
}

void Preferencias::PrintValues(){

    for(int i = 0; i < SizeofNomes(); i++){
        cout << this->nomeDados.at(i) << endl;
        for(int j = 0; j < SizeofValues(GetValuesAt(i)); j++){
            cout << this->values.at(i).at(j) << ' ';
        }
        cout << endl;
    }
}

string Preferencias::GetNameAt(int i){
    return this->nomeDados.at(i);
}

vector<float> Preferencias::GetValuesAt(int i){
    return this->values.at(i);
}

int Preferencias::SizeofNomes(){
    return this->nomeDados.size();
}

int Preferencias::SizeofValues(vector<float> vetor){
    return vetor.size();
}
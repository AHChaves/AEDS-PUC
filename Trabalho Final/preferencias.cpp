#include <iostream>
#include <iomanip>
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

int Preferencias::TableColumnsWidth(){

    int biggest = 0;

    for(const auto x:this->nomeDados)
        if(biggest < x.size())
            biggest = x.size();

    return biggest;
}

void Preferencias::PrintValues(){

    cout << setprecision(2);

    int width = TableColumnsWidth();    

    cout << setw(width+2) << "|";
    for(int i = 0; i < SizeofNomes(); i++){
       cout << setw(width)<< this->nomeDados.at(i) << " |";
    }
    cout << endl;

    cout << string(15*SizeofNomes() + 4*SizeofNomes()+ 2*width, '-') << endl;

    for(int i = 0; i < SizeofNomes(); i++){
        cout << setw(width)<< this->nomeDados.at(i) << " |";

        for(int j = 0; j < SizeofNomes(); j++){
            cout << setw(width) <<this->values.at(i).at(j) <<" |";
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
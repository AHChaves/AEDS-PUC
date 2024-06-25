#include "./headers/matrix.h"



void Matrix::AddNomes(string nome){
    this->options.push_back(nome);
}

void Matrix::AddValues(int i, float value){

    if(i >= this->values.size()){
        vector<float> v1;
        v1.push_back(value);
        this->values.push_back(v1);
    }
    else{
        this->values[i].push_back(value);
    }
}

int Matrix::TableColumnsWidth(){

    int biggest = 0;

    for(const auto x:this->options)
        if(biggest < x.size())
            biggest = x.size();

    return biggest;
}


string Matrix::GetNameAt(int i){
    return this->options.at(i);
}

vector<float> Matrix::GetValuesAt(int i){
    return this->values.at(i);
}

int Matrix::SizeofNomes(){
    return this->options.size();
}

int Matrix::SizeofValues(vector<float> vetor){
    return vetor.size();
}
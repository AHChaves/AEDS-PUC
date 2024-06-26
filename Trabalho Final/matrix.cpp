#include "./headers/matrix.h"

void Matrix::SetNames(vector<string> names){
    this->options = names;
    this->products = names;
}   

void Matrix::SetNames(vector<string> names, vector<string> products){
    this->options = names;
    this->products = products;
}   

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

vector<string> Matrix::GetNames(){
    return this->options;
}

string Matrix::GetNameAt(int i){
    return this->options.at(i);
}

vector<string> Matrix::GetProducts(){
    return this->products;
}
string Matrix::GetProductAt(int i){
    return this->products.at(i);
}

vector<float> Matrix::GetValuesAt(int i){
    return this->values.at(i);
}

int Matrix::SizeofNomes(){
    return this->options.size();
}

int Matrix::SizeofProducts(){
    return this->products.size();
}

int Matrix::SizeofValues(vector<float> vetor){
    return vetor.size();
}
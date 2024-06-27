#include <iostream>
#include <iomanip>
#include "./headers/preferencias.h"

vector<float> Preferencias::NewPriority(Matrix matrix){

    float sum;
    vector<float> line;
    vector<float> aux;

    for(int i = 0; i < matrix.SizeofProducts(); i++){
        sum = 0;
        line = matrix.GetValuesAt(i);
        for(int j = 0; j < matrix.SizeofNomes(); j++)
            sum += line.at(j);
        
        aux.push_back(sum);
    }

    return aux;
}

Matrix Preferencias::Normalization(Matrix base, vector<float> prio){

    float div;
    Matrix matrix;
    vector<float> line;

    for(int i = 0; i < base.SizeofProducts(); i++){
        line = base.GetValuesAt(i);
        for(int j = 0; j < base.SizeofNomes(); j++){
            div = line.at(j) / prio.at(i);
            matrix.AddValues(i, div);
        }
        
    }

    return matrix;
}

bool Preferencias::VerifyInconsistency(){

    bool isInconsistent;

    return isInconsistent;
}

int Preferencias::TableColumnsWidth(int i){

    int biggest = 0;

    for(const auto x:this->matrix.at(i).GetNames())
        if(biggest < x.size())
            biggest = x.size();
    
    for(const auto x:this->matrix.at(i).GetProducts())
        if(biggest < x.size())
            biggest = x.size();

    if(biggest < atribute.at(i).size())
        biggest = atribute.at(i).size();
    
    return biggest;
}

void Preferencias::PrintValues(){

    cout << setprecision(2);

    int width;
    int num_Options = this->matrix.at(0).SizeofNomes();
    int num_Products;

    for(int i = 0; i < this->atribute.size(); i++){
        width = TableColumnsWidth(i);
        num_Products = this->matrix.at(i).SizeofProducts();

        cout << setw(width) << this->atribute.at(i) << " | ";
        for(int j = 0; j < num_Options; j++){
            cout << setw(width) << this->matrix.at(i).GetNameAt(j) 
            << " | ";
        }
        cout << endl;

        cout << string(12*num_Options + 2*width, '-')
        << endl;

        for(int j = 0; j < num_Products; j++){
            cout << setw(width)<< this->matrix.at(i).GetProductAt(j) 
            << " | ";

            for(int k = 0; k < num_Options; k++){
                cout << setw(width) << this->matrix.at(i).GetValuesAt(j).at(k)
                <<" | ";
            }
            cout << endl;
        } 

        cout << "\n--------------------------------------------------\n\n";
    }

    for(int i = 0; i < 1; i++){
        width = TableColumnsWidth(i);
        
        for(int j = 0; j < num_Products; j++){

            for(int k = 0; k < num_Options; k++){
                cout << setw(width) << this->normalization.at(i).GetValuesAt(j).at(k)
                <<" | ";
            }
            cout << endl;
        } 

        cout << "\n--------------------------------------------------\n\n";
    }
}
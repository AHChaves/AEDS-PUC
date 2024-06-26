#include <iostream>
#include <iomanip>
#include "./headers/preferencias.h"

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
    int num_Products = this->matrix.at(0).SizeofProducts();

    for(int i = 0; i < this->atribute.size(); i++){
        width = TableColumnsWidth(i);

        cout << setw(width) << this->atribute.at(i) << " | ";
        for(int j = 0; j < num_Options; j++){
            cout << setw(width) << this->matrix.at(i).GetNameAt(j) 
            << " | ";
        }
        cout << endl;

        cout << string(12*num_Options + width, '-')
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
}
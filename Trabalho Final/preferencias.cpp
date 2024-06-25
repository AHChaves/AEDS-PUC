#include <iostream>
#include <iomanip>
#include "./headers/preferencias.h"


void Preferencias::PrintValues(){

    cout << setprecision(2);
    int width_Matrix = this->matrix.at(0).TableColumnsWidth();
    int width_Atribute, biggest_width;
    int num_Options = this->matrix.at(0).SizeofNomes();

    for(int i = 0; i < this->atribute.size(); i++){
        width_Atribute = this->atribute.at(i).size();
        biggest_width = (width_Atribute > width_Matrix) ? biggest_width : width_Matrix;    

        cout << setw(biggest_width) << this->atribute.at(i) << " |";
        for(int j = 0; j < num_Options; j++){
            cout << setw(biggest_width) << this->matrix.at(i).GetNameAt(j) 
            << " |";
        }
        cout << endl;

        cout << string(12*num_Options + biggest_width, '-')
        << endl;

        for(int j = 0; j < num_Options; j++){
            cout << setw(biggest_width)<< this->matrix.at(i).GetNameAt(j) 
            << " |";

            for(int k = 0; k < num_Options; k++){
                cout << setw(biggest_width) << this->matrix.at(i).GetValuesAt(j).at(k)
                <<" |";
            }
            cout << endl;
        } 

        cout << "\n--------------------------------------------------\n";
    }
}
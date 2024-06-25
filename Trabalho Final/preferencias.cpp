#include <iostream>
#include <iomanip>
#include "./headers/preferencias.h"

// void Preferencias::PrintValues(){

//     cout << setprecision(2);

//     int width = this->matrix.at();    

//     cout << setw(width+2) << "|";
//     for(int i = 0; i < SizeofNomes(); i++){
//        cout << setw(width)<< this->options.at(i) << " |";
//     }
//     cout << endl;

//     cout << string(15*SizeofNomes() + 4*SizeofNomes()+ 2*width, '-') << endl;

//     for(int i = 0; i < SizeofNomes(); i++){
//         cout << setw(width)<< this->options.at(i) << " |";

//         for(int j = 0; j < SizeofNomes(); j++){
//             cout << setw(width) <<this->values.at(i).at(j) <<" |";
//         }
//         cout << endl;
//     }
// }
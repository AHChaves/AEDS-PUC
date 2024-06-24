#include <iostream>
#include "./headers/prefNumerical.h"

void Preferencias_Numericas::AtribuirDados(){
    
    string name;
    float value;
    int option;

    do{

        cout << "Deseja continuar inserindo categorias de comparação" << endl;
        cout << "[1] Continuar" << endl;
        cout << "[0] Parar" << endl;
        cout << '>';
        cin >> option;

        switch(option){

            case 1:
                cout << "Insira o nome da categoria: " << endl;
                cin >> name;
                this->AddNomes(name);   

                for(int i =0; i < SizeofNomes(); i++){
                    if(name.compare(GetNameAt(i)) == 0){
                        value = 1;
                    }
                    else{
                        cout << "Informe o quão importante esse dado é em comparação com " << GetNameAt(i) << endl;
                        cin >> value;
                    }
                    AddValues(SizeofNomes() -1, value);
                }
                break;
            case 0: break;
            default:
                cout << "opção invalida!" << endl;
                break;
        }
    }while(option != 0);

}
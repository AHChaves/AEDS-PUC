#include <iostream>
#include "./headers/prefNumerical.h"

void Preferencias_Numericas::AtribuirDados(){
    
    string nome;
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
                cin >> nome;
                this->AddNomes(nome);   

                for(int i =0; i < SizeofNomes(); i++){
                    cout << "Informe o quão importante esse dado é em comparação com " << GetNameAt(i) << endl;
                    cin >> value;
                    AddValues(i, value);
                }
                break;
            case 0: break;
            default:
                cout << "opção invalida!" << endl;
                break;
        }
    }while(option != 0);

}
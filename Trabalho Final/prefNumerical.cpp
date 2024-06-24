#include <iostream>
#include "./headers/prefNumerical.h"

void Preferencias_Numericas::InserirCategoria(){
    string name;
    float value;

    cout << "Insira o nome da categoria: " << endl;
    getline(cin, name);
    AddNomes(name);   

    for(int i = 0; i < SizeofNomes(); i++){
        if(name.compare(GetNameAt(i)) == 0){
            value = 1;
        }
        else{
            cout << "Informe o quao importante esse dado eh em comparacao com " 
            << GetNameAt(i) << endl;
            cin >> value;
            AddValues(i, (1/value));
        }
        AddValues(SizeofNomes() - 1, value);
    }
}

void Preferencias_Numericas::AtribuirDados(){
    
    int option;

    InserirCategoria();
    InserirCategoria();

    do{

        cout << "Deseja continuar inserindo categorias de comparacao?" << endl;
        cout << "[1] Continuar" << endl;
        cout << "[0] Parar" << endl;
        cout << "> ";
        cin >> option;

        getchar();

        switch(option){

            case 1:
                InserirCategoria();
                break;
            case 0: break;
            default:
                cout << "opcao invalida!" << endl;
                break;
        }
        
    }while(option != 0);

}
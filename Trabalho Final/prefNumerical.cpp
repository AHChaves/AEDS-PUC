#include <iostream>
#include "./headers/prefNumerical.h"

vector<string> Preferencias_Numericas::Name_Options(){

    string aux;
    vector<string> names;
    int option;

    do{

        cout << "Escolha uma opcao" << endl;
        cout << "[0] Sair" << endl;
        cout << "[1] Inserir nova opcao" << endl;
        cout << "> ";
        cin >> option;

        getchar();

        switch (option)
        {
        case 0:
            if(names.size() <  2){
                cout << "Insira pelo menos 2 opcoes de comparacao!" << endl;
                option = 1;
            }
            break;
        case 1:
            cout << "Nome da opcao: ";
            getline(cin, aux);
            names.push_back(aux);
            break;
        default:
            cout << "Opcao invaldia!" << endl;
            break;
        }

    }while(option != 0);

    return names;
}

void Preferencias_Numericas::InsertValues(){
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
    vector<string> optionsNames = Name_Options();

    InsertValues();
    InsertValues();

    do{

        cout << "Deseja continuar inserindo categorias de comparacao?" << endl;
        cout << "[1] Continuar" << endl;
        cout << "[0] Parar" << endl;
        cout << "> ";
        cin >> option;

        getchar();

        switch(option){

            case 1:
                InsertValues();
                break;
            case 0: break;
            default:
                cout << "opcao invalida!" << endl;
                break;
        }
        
    }while(option != 0);

}
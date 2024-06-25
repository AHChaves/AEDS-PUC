#include <iostream>
#include "./headers/prefNumerical.h"

vector<string> Preferencias_Numericas::Name_Options(){

    string aux;
    vector<string> names;
    int option;

    do{

        cout << "Escolha uma opcao" << endl;
        cout << "[0] Sair" << endl;
        cout << "[1] Inserir opcao" << endl;
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

void Preferencias_Numericas::InsertMatrix(vector<string> names){
    
    string name;
    float value;
    Matrix aux;

    cout << "Insira o nome do atributo: " << endl;
    getline(cin, name);
    this->atribute.push_back(name);

    aux.SetNames(names);

    for(int i = 0; i < aux.SizeofNomes(); i++){
        for(int j = 0; j <= i; j++){
            if(j == i){
                value = 1;
            }
            else{
                cout << "Informe o quao melhor esse dado na " 
                << aux.GetNameAt(i)<< " eh melhor do que na " << aux.GetNameAt(j) 
                << endl;
                cin >> value;
                aux.AddValues(j, (1/value));
            }
            aux.AddValues(i, value);
        }
    }

    this->matrix.push_back(aux);
}

void Preferencias_Numericas::AtribuirDados(){
    
    int option;
    vector<string> optionsNames = Name_Options();

    InsertMatrix(optionsNames);

    do{

        cout << "Deseja continuar inserindo categorias de comparacao?" << endl;
        cout << "[1] Continuar" << endl;
        cout << "[0] Parar" << endl;
        cout << "> ";
        cin >> option;

        getchar();

        switch(option){

            case 1:
                InsertMatrix(optionsNames);
                break;
            case 0: break;
            default:
                cout << "opcao invalida!" << endl;
                break;
        }
        
    }while(option != 0);

}
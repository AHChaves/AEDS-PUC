#include <iostream>
#include "./headers/prefNumerical.h"

vector<string> Preferencias_Numericas::Name_Options(){

    string aux;
    vector<string> names;
    int option;

    do{

        cout << "Escolha uma opcao" << endl;
        cout << "[0] Sair" << endl;
        cout << "[1] Inserir dado" << endl;
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
            cout << "Nome do dado: ";
            getline(cin, aux);
            names.push_back(aux);
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

    }while(option != 0);

    return names;
}

void Preferencias_Numericas::InsertMatrix(vector<string> names){
    
    string name;
    float value;
    Matrix aux;

    cout << "Insira o nome da tabela: " << endl;
    getline(cin, name);
    this->atribute.push_back(name);

    aux.SetNames(names);

    for(int i = 0; i < aux.SizeofNomes(); i++){
        for(int j = 0; j <= i; j++){
            if(j == i){
                value = 1;
            }
            else{
                cout << "Informe o quao melhor " 
                << aux.GetNameAt(i)<< " eh em comparacao com " << aux.GetNameAt(j) 
                << endl;
                cin >> value;
                aux.AddValues(j, (1/value));
            }
            aux.AddValues(i, value);
        }
    }

    this->matrix.push_back(aux);
}

void Preferencias_Numericas::InsertMatrix(vector<string> names, vector<string> products){

    string name;
    float value;
    Matrix aux;

    cout << "Insira o nome da tabela: " << endl;
    getline(cin, name);
    this->atribute.push_back(name);

    aux.SetNames(names, products);

    for(int i = 0; i < aux.SizeofNomes(); i++){
        for(int j = 0; j <= aux.SizeofProducts(); j++){
            cout << "Informe a qualidade do produto " << aux.GetNameAt(i) << " na categoria de "
            << aux.GetNameAt(j) << endl;
            cin >> value;
            aux.AddValues(j, value);
        }
    }
}

void Preferencias_Numericas::AtribuirDados(){
    
    int option;
    
    cout << "Informe os nomes das bases de comparacao" << endl;
    vector<string> optionsNames = Name_Options();

    cout << "Informe os nomes dos produtos" << endl;
    vector<string> productsNames = Name_Options();

    InsertMatrix(optionsNames);

    InsertMatrix(optionsNames, productsNames);

}
#include <iostream>
#include "./headers/prefNumerical.h"

void Preferencias_Numericas::AtribuirDados(){
    
    string nome;
    float valor;

    cout << "Insira o nome dacategoria: " << endl;
    cin >> nome;
    this->AddNomes(nome);   

    for(int i =0; i < SizeofNomes(); i++){
        cout << "Informe o quão importante esse dado é em comparação com " << GetNameAt(i) << endl;
        cin >> valor;
        AddValores(GetValuesAt(i),valor);
    }

}
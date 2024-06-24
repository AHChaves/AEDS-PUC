#include <iostream>
#include <locale>
#include "./headers/prefNumerical.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    Preferencias_Numericas* pref = new Preferencias_Numericas;

    pref->AtribuirDados();
    pref->PrintValues();

    return 0;
}
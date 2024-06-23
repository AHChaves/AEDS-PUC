#include <iostream>
#include "./headers/prefNumerical.h"


int main(){

    Preferencias_Numericas* pref = new Preferencias_Numericas;

    pref->AtribuirDados();
    pref->PrintValues();

    return 0;
}
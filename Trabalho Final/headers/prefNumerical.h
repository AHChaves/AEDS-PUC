#ifndef PREF_NUMERICA
#define PREF_NUMERICA
#include "preferencias.h"

class Preferencias_Numericas: public Preferencias{

    void InsertValues();
    vector<string> Name_Options();

    public:
        Preferencias_Numericas(){};
        ~Preferencias_Numericas(){};
        void AtribuirDados() override;
};

#endif
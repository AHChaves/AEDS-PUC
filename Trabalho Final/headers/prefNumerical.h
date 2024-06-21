#pragma once
#include "preferencias.h"

class Preferencias_Numericas: public Preferencias{

    public:
        Preferencias_Numericas(){};
        ~Preferencias_Numericas();
        void AtribuirDados() override;
};
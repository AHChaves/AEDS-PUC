#ifndef PREF
#define PREF
#include "matrix.h"

class Preferencias{

private:
    vector<string> atribute;
    vector<Matrix> matrix;

public:
    Preferencias(){};
    ~Preferencias(){};
    
    //Adicionar value
    virtual void AtribuirDados() = 0;
    
    //impressão
    void PrintValues();
    
};

#endif 
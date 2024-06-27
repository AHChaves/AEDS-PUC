#ifndef PREF
#define PREF
#include "matrix.h"

class Preferencias{

protected:
    vector<string> atribute;
    vector<Matrix> matrix;
    vector<Matrix> normalization;
    vector<vector<float>> priority;

public:

    Preferencias(){};
    ~Preferencias(){};
    
    // Ajustes de valores
    vector<float> NewPriority(Matrix matrix);
    Matrix Normalization(Matrix base, vector<float> prio);
    bool VerifyInconsistency();

    //Adicionar value
    virtual void AtribuirDados() = 0;
    
    //impressão
    int TableColumnsWidth(int i);
    void PrintValues();

};

#endif 
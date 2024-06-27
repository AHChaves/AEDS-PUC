#ifndef PREF
#define PREF
#include "matrix.h"

class Preferencias{

protected:
    vector<string> atribute;
    vector<Matrix> matrix;
    vector<vector<float>> priority;

public:

    Preferencias(){};
    ~Preferencias(){};
    
    // Ajustes de valores
    vector<float> SumLines(Matrix matrix);
    Matrix Normalization(Matrix base, vector<float> prio);
    vector<float> NewPriority(Matrix base);
    bool VerifyInconsistency();

    //Adicionar value
    virtual void AtribuirDados() = 0;
    
    //impressão
    int TableColumnsWidth(int i);
    void PrintValues();

};

#endif 
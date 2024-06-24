#ifndef PREF
#define PREF
#include <string>
#include <vector>

using namespace std;

class Preferencias{

private:
    vector<string> nomeDados;
    vector<vector<float>> values;

public:
    Preferencias(){};
    ~Preferencias(){};
    
    //Adicionar value
    void AddNomes(string nome);
    void AddValues(int i, float value);
    virtual void AtribuirDados(){};
    
    //impressão
    int TableColumnsWidth();
    void PrintValues();

    //value na posição i
    string GetNameAt(int i);
    vector<float> GetValuesAt(int i);
    
    //tamanho
    int SizeofNomes();
    int SizeofValues(vector<float> vetor);
};

#endif 
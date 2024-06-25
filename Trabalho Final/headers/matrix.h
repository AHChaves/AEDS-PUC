#ifndef MATRIX
#define MATRIX
#include <string>
#include <vector>

using namespace std;

class Matrix{

    vector<string> options;
    vector<vector<float>> values;

public:

    //Adicionar value
    void AddNomes(string nome);
    void AddValues(int i, float value);

    //Impressao
    int TableColumnsWidth();

    //value na posição i
    string GetNameAt(int i);
    vector<float> GetValuesAt(int i);
    
    //tamanho
    int SizeofNomes();
    int SizeofValues(vector<float> vetor);

};

#endif
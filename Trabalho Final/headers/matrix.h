#ifndef MATRIX
#define MATRIX
#include <string>
#include <vector>

using namespace std;

class Matrix{

    vector<string> options;
    vector<string> products;
    vector<vector<float>> values;

public:

    //Adicionar value
    void SetNames(vector<string> names);
    void SetNames(vector<string> names, vector<string> products);
    void AddNomes(string nome);
    void AddValues(int i, float value);

    //value na posição i
    vector<string> GetNames();
    string GetNameAt(int i);

    vector<string> GetProducts();
    string GetProductAt(int i);
    vector<float> GetValuesAt(int i);
    
    //tamanho
    int SizeofNomes();
    int SizeofProducts();
    int SizeofValues(vector<float> vetor);

};

#endif
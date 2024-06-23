#include <string>
#include <vector>

using namespace std;

class Preferencias{

private:
    vector<string> nomeDados;
    vector<vector<float>> valores;

public:
    Preferencias(){};
    ~Preferencias(){};
    
    //Adicionar valores
    void AddNomes(string nome);
    void AddValores(vector<float> lista, float valor);
    virtual void AtribuirDados();
    
    //impressão
    void PrintValues();

    //valores na posição i
    string GetNameAt(int i);
    vector<float> GetValuesAt(int i);
    
    //tamanho
    int SizeofNomes();
    int SizeofValores(vector<float> vetor);
};
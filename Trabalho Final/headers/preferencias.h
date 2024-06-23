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
    void AddNomes(string nome);
    void AddValores(vector<float> lista, float valor);
    string GetNameAt(int i);
    vector<float> GetValuesAt(int i);
    int SizeofNomes();
    virtual void AtribuirDados();
};
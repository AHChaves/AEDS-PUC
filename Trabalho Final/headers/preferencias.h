#include <string>
#include <list>

using namespace std;

class Preferencias{

private:
    list<string> nomeDados ;
    list<float> valores;

public:
    Preferencias(){};
    ~Preferencias();
    void AddNomes(string nome);
    void AddValores(float valor);
    virtual void AtribuirDados();

};
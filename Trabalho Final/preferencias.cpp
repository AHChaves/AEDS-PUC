#include <string>
#include <list>

using namespace std;

class Preferencias{

    private:
        string nomeGeral;
        char tipo;
        list<string> nomeDados ;
        list<float> valores;

    public:


        string GetNomeGeral(){
            return this->nomeGeral;
        }

        void SetNomeGeral(string nomeGeral){
            this->nomeGeral = nomeGeral;
        }

        char GetTipo(){
            return this->tipo;
        }

        char SetTipo(char tipo){
            this->tipo = tipo;
        }

        list<string> GetNomeDados(){
            return this->nomeDados;
        }

        list<string> SetNomeDados(list<string> nomeDados){
            this->nomeDados = nomeDados;
        }

        list<float> GetValores(){
            return this->valores;
        }

        list<string> SetValores(list<float> valores){
            this->valores = valores;
        }
};
#include <stdio.h>
#include <stdlib.h>

#define TAM_STRING (50+1)
#define NOME_ARQUIVO "AHP.bin"

typedef struct criterios_t
{
    float** mCriterios; // criteirios[nCriterios][nOpcao][nOpcao]
    float* mediaCriterios; // mediaCriterios[nCriteiros][nOpcao]
}Criterios_s;


typedef struct Matriz_t{

    char titulo[TAM_STRING];

    int nOpcao;
    char* opcao[TAM_STRING];
    
    int nCriterios;
    char* nomeCriterios[TAM_STRING]; 
    Criterios_s* criterios;


    float** criteriosGerais; // criteirios[nCriterios][nCriterios]
    float* mediaCriteriosGerais; // mediaCriteriosGerais[nCriterios]

}Matriz_s;

void CadastraDados(Matriz_s* matriz);
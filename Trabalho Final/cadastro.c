#include "matriz_decisao.h"


void AllocaCriterios(Criterios_s* criterios, int nOpcao, int nCriterios){

    for(i = 0; i < nOpcao; i++){
        criterios->mCriterios[i] = (float**)malloc(nCriterios*sizeof(float*));
        for(j = 0; j <nCriterios; j++){
            criterios->mCriterios[i][j] = (float*)malloc(nCriterios*sizeof(float));
        
        
        
        }
    
    }

    

}

void CadastraDados(Matriz_s* matriz){

    FILE* file = fopen(NOME_ARQUIVO, "ab");
    int i, j, k;

    if(file == NULL){
        printf("O arquivo não abriu");
    }
    else{
        printf("Insira o nome da secao: ");
        fgets(matriz->titulo, TAM_STRING, stdin);


        printf("Informe quantas opcoes voce esta em duvida: ");
        scanf("%d%*c", &matriz->nOpcao);
        matriz->opcao = (char*)malloc(matriz->nOpcao*sizeof(char));


        for(i = 0; i < matriz->nOpcao; i++){
            printf("Insira o nome das categorias: ");
            fgets(matriz->opcao, TAM_STRING, stdin);
        }

        printf("Informe quantas criterios voce tem: ");
        scanf("%d%*c", &matriz->nCriterios);

        matriz->nomeCriterios = (char*)malloc(matriz->nCriterios*sizeof(char));
        printf("Insira o nome da secao: ");
        fgets(matriz->nomeCriterios, TAM_STRING, stdin);

        matriz->criterios = (Criterios_s*)malloc(matriz->nOpcao*sizeof(Criterios_s));
        AllocaCriterios(matriz->criterios, matriz->nOpcao, matriz->nCriterios);




    }

}
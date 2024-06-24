#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>

#define TAM_VETORES 4

void InicializaVetor(float* vetor){
    for(int i = 0; i < TAM_VETORES; i++)
        vetor[i] = FLT_MAX;
}

void ImprimeResultTransporte(float dist, float* result, float vel, float tempTrans){
    *result = dist * vel + tempTrans;
    printf(" %f min\n", *result);
}

void ImprimeTempoOpcoes(float distancia, float* resultados){

    float distMin[TAM_VETORES] = {0.0, 1.0, 0.5, 0.0}, 
          distMax[TAM_VETORES] = {1.0, 10.0, 5.0, 10.0};

    float velocidade[TAM_VETORES] = {11.0, 4.5, 3.0, 2.0},
          tempoTransporte[TAM_VETORES] = {0.0, 7.0, 12.0, 20.0}; 

    bool metodo_transporte_valido;

    char *lista_transportes[TAM_VETORES] = {"A pe", "Onibus", "Taxi", "MotoTaxi"};

    for(int i = 0; i < TAM_VETORES; i++){
        metodo_transporte_valido = (distancia >= distMin[i] && distancia <= distMax[i]) ? true : false;

        printf("%s: ", lista_transportes[i]);

        if(!metodo_transporte_valido){
            printf("não se aplica.\n");
        }    
        else ImprimeResultTransporte(distancia, &resultados[i], velocidade[i], tempoTransporte[i]);
    }
}

void ComparacaoMenorTempo(float* resultados){

    float menorTempo = FLT_MAX;
    int indice_do_menor;

    for(int i = 0; i < TAM_VETORES; i++){
        if(menorTempo > resultados[i]){
            indice_do_menor = i;
            menorTempo = resultados[i];
        }
    }

    switch (indice_do_menor)
    {
    case 0:
        printf("transporte escolhido: a pe\n");
        break;
    case 1:
        printf("transporte escolhido: Onibus\n");
        break;
    case 2:
        printf("transporte escolhido: Taxi\n");
        break;
    case 3:
        printf("transporte escolhido: Mototaxi\n");
        break;    
    default:
        printf("distancia invalida!\n");
        break;
    }
}

int main(){

    float distancia;
    float resultados[TAM_VETORES];

    do{
        InicializaVetor(resultados);

        printf("Informe a distancia até o destino (insira o value negativo para finalizar o programa): ");
        scanf("%f", &distancia);

        ImprimeTempoOpcoes(distancia, resultados);

        ComparacaoMenorTempo(resultados);

        printf("\n---------------------------------------------------------------\n\n");

    }while(distancia >= 0);

    return 0;
}
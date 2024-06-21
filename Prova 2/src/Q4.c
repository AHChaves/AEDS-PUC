#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Media(float* v, int n){

    float soma = 0;

    for(int i =0; i < n; i++){
        soma += v[i];
    }

    return soma/n;
}

double DesvioPadrao(float* v, int n, float media){

    double desvio;
    float sub = 0;

    for(int i = 0; i < n; i++)
        sub += pow((v[i]-media),2 );
    
    desvio = sqrt(sub/(n-1));

    return desvio;
}

int main(){

    float* vetor, media;
    double desvio;
    int nElementos;

    printf("Informe o numero de elementos: ");
    scanf("%d", &nElementos);

    vetor = (float*)malloc(sizeof(float)*nElementos);

    for(int i = 0; i < nElementos; i++){
        printf("Informe o valor na posicao %d: ", (i+1));
        scanf("%f", &vetor[i]);
    }

    media = Media(vetor, nElementos);

    desvio = DesvioPadrao(vetor, nElementos, media);

    printf("Media: %f\nDesvio Padrao: %lf", media, desvio);

    return 0;
}
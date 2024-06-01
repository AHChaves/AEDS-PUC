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

float DesvioPadrao(float* v, int n, int media){

    float desvio, sub;

    for(int i = 0; i < n; i++)
        sub += v[i]-media;
    
    desvio = sqrt(pow(sub, 2)/(n-1));

    return desvio;
}

int main(){

    float* vetor, media, desvio;
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

    printf("Media: %f\nDesvio Padrao: %f", media, desvio);

    return 0;
}
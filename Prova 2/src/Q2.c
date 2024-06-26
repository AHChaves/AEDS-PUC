#include <stdio.h>
#include <stdlib.h>

int InverteVetorAchaMaior(int* v1, int* v2, int n){

    int maior = 0;

    for(int i = 0, j = (n-1); i < n; i++, j--){

        v2[j] = v1[i];

        if(maior < v1[i])
            maior = v1[i];

    }

    return maior;
}

int main(){

    int *v1, *v2, n, maior_value;

    printf("Informe a quantidade de elementos: ");
    scanf("%d", &n);

    v1 = (int*)malloc(sizeof(int)*n);
    v2 = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++)
        v1[i] = i;

    maior_value = InverteVetorAchaMaior(v1, v2, n);

    printf("Maior value: %d", maior_value);

    free(v1);
    free(v2);
    
    return 0;
}
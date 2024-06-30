#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto_t {
    double x;
    double y;
}Ponto_s;

double Distancia(Ponto_s a, Ponto_s b){

    double soma_x, soma_y, resultado;

    soma_x = abs(b.x)-abs(a.x);
    soma_y = abs(b.y)-abs(a.y);

    resultado = sqrt( pow(soma_x,2) + pow(soma_y,2));

    return resultado;
}

Ponto_s MaisProximoOrigem(){

    Ponto_s* pontos;
    Ponto_s zero, maisProximo;
    int nPontos, menor_distancia, distancia_I;

    zero.x = 0;
    zero.y = 0;

    printf("Informe quantos pontos vão ser gravados: ");
    scanf("%d", &nPontos);

    pontos = (Ponto_s*)malloc(sizeof(Ponto_s)*nPontos);

    for(int i = 0; i < nPontos; i++){
        printf("Informe, para o ponto n%d, os value de x e y(nesse padrao: 'x y'): ", (i+1));
        scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
        
        distancia_I = Distancia(zero, pontos[i]);

        if((menor_distancia > distancia_I) || (i == 0)){
            menor_distancia = distancia_I;
            maisProximo = pontos[i];
        }
    }

    free(pontos);

    return maisProximo;
}

int main(){

    FILE* arquivo;
    Ponto_s proximo_origem;

    arquivo = fopen("questao1.txt", "w");
    
    if(arquivo == NULL)
        return -1;

    proximo_origem = MaisProximoOrigem();

    printf("(%lf, %lf)", proximo_origem.x, proximo_origem.y);

    fwrite(&proximo_origem, sizeof(Ponto_s), 1, arquivo);

    return 0;
}
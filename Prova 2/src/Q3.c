#include <stdio.h>

int encontrarX(int vetor[], int i, int n)
{
    if (i == n - 1)
    {
        return vetor[i];
    }
    int XResto = encontrarX(vetor, i + 1, n);
    return (vetor[i] < XResto) ? vetor[i] : XResto;
}

int main()
{
    int n;
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    int X = encontrarX(vetor, 0, n);
    printf("O X eh: %d\n", X);
    return 0;
}
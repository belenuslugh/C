#include <stdio.h>
#include <math.h>

double calcularMedia(int numeros[], int tamanho);
double calcularVariancia(int numeros[], int tamanho, double media);
double calcularDesvioPadrao(double variancia);
int encontrarModa(int numeros[], int tamanho);

int main() {
    int numeros[15];
    double media, desvioPadrao, variancia;
    int moda;
    
    for(int i = 0; i < 15; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    media = calcularMedia(numeros, 15);
    variancia = calcularVariancia(numeros, 15, media);
    desvioPadrao = calcularDesvioPadrao(variancia);
    moda = encontrarModa(numeros, 15);
    
    printf("\nMédia: %.2f\n", media);
    printf("Variância: %.2f\n", variancia);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Moda: %d\n", moda);
    
    return 0;
}

double calcularMedia(int numeros[], int tamanho) {
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return soma / tamanho;
}

double calcularVariancia(int numeros[], int tamanho, double media) {
    double somaQuadrados = 0;
    for(int i = 0; i < tamanho; i++) {
        somaQuadrados += pow((numeros[i] - media), 2);
    }
    return somaQuadrados / tamanho;
}

double calcularDesvioPadrao(double variancia) {
    return sqrt(variancia);
}

int encontrarModa(int numeros[], int tamanho) {
    int moda = numeros[0];
    int maiorFrequencia = 0;
    
    for(int primeiro  = 0; primeiro  < tamanho; primeiro ++) {
        int frequenciaAtual = 0;
        for(int segundo = 0; segundo < tamanho; segundo++) {
            if(numeros[primeiro ] == numeros[segundo]) {
                frequenciaAtual++;
            }
        }
        if(frequenciaAtual > maiorFrequencia || (frequenciaAtual == maiorFrequencia && numeros[primeiro ] > moda)) {
            maiorFrequencia = frequenciaAtual;
            moda = numeros[primeiro ];
        }
    }
    return moda;
}

#include <stdio.h>
#include <stdlib.h> 

#define MAX_PARTIDAS 100 

// --- PROTÓTIPOS DAS FUNÇÕES ---
int* alocarHistorico(int tamanho);
void preencherHistorico(int *historico, int tamanho);
void exibirHistorico(const int *historico, int tamanho);
float calcularMedia(const int *historico, int tamanho);
void localizarMaiorPontuacao(const int *historico, int tamanho, int *maiorValor, int *posicaoMaior);

int main() {
    int quantidade = 0;

    printf("===========================================\n");
    printf("     SISTEMA DE HISTORICO DE PARTIDAS      \n");
    printf("===========================================\n\n");

    printf("Informe a quantidade de partidas a registrar (1 a %d): ", MAX_PARTIDAS);
    if (scanf("%d", &quantidade) != 1) {
        printf("Erro: Entrada invalida!\n");
        return 1;
    }

    
    int *historico = alocarHistorico(quantidade);

    
    if (historico == NULL) {
        printf("\n[ERRO] Falha ao criar o historico! Tamanho invalido ou memoria insuficiente.\n");
        return 1;
    }

    printf("\nHistorico alocado com sucesso para %d partida(s)!\n\n", quantidade);

    
    preencherHistorico(historico, quantidade);
    
    printf("\n===========================================\n");
    exibirHistorico(historico, quantidade);

    
    float media = calcularMedia(historico, quantidade);
    printf("Media de pontos por partida: %.2f\n", media);

    
    int maiorPontuacao, posicao;
    localizarMaiorPontuacao(historico, quantidade, &maiorPontuacao, &posicao);
    printf("Maior resultado: %d pontos (alcancado na Partida %d)\n", maiorPontuacao, posicao + 1);
    printf("===========================================\n");

    
    free(historico);
    historico = NULL; 

    printf("\nMemoria liberada com sucesso. Fim da execucao!\n");

    return 0;
}


int* alocarHistorico(int tamanho) {
    if (tamanho <= 0 || tamanho > MAX_PARTIDAS) {
        return NULL; 
    }

    
    int *vetor = (int*) malloc(tamanho * sizeof(int));

    
    return vetor;
}


void preencherHistorico(int *historico, int tamanho) {
    printf("--- Digitacao dos Resultados ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pontuação da Partida %d: ", i + 1);
        scanf("%d", &historico[i]);
    }
}


void exibirHistorico(const int *historico, int tamanho) {
    printf("Historico de pontuacoes: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", historico[i]);
    }
    printf("]\n");
}


float calcularMedia(const int *historico, int tamanho) {
    if (tamanho <= 0) return 0.0f;

    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += historico[i];
    }

    
    return (float)soma / tamanho;
}


void localizarMaiorPontuacao(const int *historico, int tamanho, int *maiorValor, int *posicaoMaior) {
    if (tamanho <= 0) return;

    int maior = historico[0];
    int pos = 0;

    for (int i = 1; i < tamanho; i++) {
        if (historico[i] > maior) {
            maior = historico[i];
            pos = i;
        }
    }

    *maiorValor = maior;
    *posicaoMaior = pos;
}
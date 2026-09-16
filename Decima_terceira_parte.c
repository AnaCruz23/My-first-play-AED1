                #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

float* criar_matriz_continua(size_t linhas, size_t colunas) {
    if (linhas == 0 || colunas == 0) return NULL;

    // Validação contra overflow de multiplicacao ao calcular o tamanho total
    if (linhas > SIZE_MAX / colunas) {
        printf("Erro: Estouro de limite na dimensao da matriz.\n");
        return NULL;
    }

    size_t total_elementos = linhas * colunas;

    if (total_elementos > SIZE_MAX / sizeof(float)) {
        printf("Erro: Estouro de limite (overflow) na quantidade de bytes requisitados.\n");
        return NULL;
    }

    float *matriz = (float*) malloc(total_elementos * sizeof(float));
    return matriz; // Pode retornar NULL se o malloc falhar
}

void preencher_matriz_continua(float *matriz, size_t linhas, size_t colunas) {
    if (!matriz) return;
    float valor = 1.0f;
    for (size_t r = 0; r < linhas; r++) {
        for (size_t c = 0; c < colunas; c++) {
            // Acesso via deslocamento linear: linha * colunas + coluna
            matriz[r * colunas + c] = valor++;
        }
    }
}

void exibir_matriz_continua(const float *matriz, size_t linhas, size_t colunas) {
    if (!matriz) {
        printf("Matriz continua vazia/inexistente.\n");
        return;
    }
    printf("\n--- Matriz Continua (Offset Linear) ---\n");
    for (size_t r = 0; r < linhas; r++) {
        for (size_t c = 0; c < colunas; c++) {
            printf("%6.1f ", matriz[r * colunas + c]);
        }
        printf("\n");
    }
}

void liberar_matriz_continua(float **matriz) {
    if (matriz && *matriz) {
        free(*matriz);
        *matriz = NULL;
    }
}

// ==========================================
// OPERAÇÕES - MATRIZ DE PONTEIROS (2D)
// ==========================================

float** criar_matriz_ponteiros(size_t linhas, size_t colunas) {
    if (linhas == 0 || colunas == 0) return NULL;

    // Validação de overflow na quantidade de linhas e colunas
    if (linhas > SIZE_MAX / sizeof(float*)) return NULL;
    if (colunas > SIZE_MAX / sizeof(float)) return NULL;

    // 1. Aloca o vetor principal de ponteiros para as linhas
    float **matriz = (float**) malloc(linhas * sizeof(float*));
    if (!matriz) return NULL;

    // 2. Aloca cada linha individualmente com tratamento defensivo
    for (size_t r = 0; r < linhas; r++) {
        matriz[r] = (float*) malloc(colunas * sizeof(float));
        
        // Em caso de falha parcial, desaloca todas as linhas já criadas anteriormente
        if (!matriz[r]) {
            for (size_t i = 0; i < r; i++) {
                free(matriz[i]);
            }
            free(matriz);
            printf("Erro: Falha na alocacao parcial da linha %zu. Memoria liberada.\n", r);
            return NULL;
        }
    }

    return matriz;
}

void preencher_matriz_ponteiros(float **matriz, size_t linhas, size_t colunas) {
    if (!matriz) return;
    float valor = 1.0f;
    for (size_t r = 0; r < linhas; r++) {
        for (size_t c = 0; c < colunas; c++) {
            matriz[r][c] = valor++;
        }
    }
}

void exibir_matriz_ponteiros(float **matriz, size_t linhas, size_t colunas) {
    if (!matriz) {
        printf("Matriz de ponteiros vazia/inexistente.\n");
        return;
    }
    printf("\n--- Matriz de Linhas Independentes (Ponteiro de Ponteiros) ---\n");
    for (size_t r = 0; r < linhas; r++) {
        for (size_t c = 0; c < colunas; c++) {
            printf("%6.1f ", matriz[r][c]);
        }
        printf("\n");
    }
}

void liberar_matriz_ponteiros(float ***matriz, size_t linhas) {
    if (matriz && *matriz) {
        // Libera cada linha individualmente
        for (size_t r = 0; r < linhas; r++) {
            if ((*matriz)[r]) {
                free((*matriz)[r]);
            }
        }
        // Libera o vetor de ponteiros
        free(*matriz);
        *matriz = NULL;
    }
}

// ==========================================
// MENU INTEGRADO
// ==========================================

int main() {
    float *m_continua = NULL;
    float **m_ponteiros = NULL;
    size_t linhas = 0, colunas = 0;
    int opcao = 0;

    do {
        printf("\n================ MENU ================\n");
        printf("Dimensao atual: %zu x %zu\n", linhas, colunas);
        printf("1. Definir dimensoes e Alocar matrizes\n");
        printf("2. Preencher matrizes\n");
        printf("3. Exibir matrizes\n");
        printf("4. Liberar matrizes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // Limpa buffer de entrada inválida
            continue;
        }

        switch (opcao) {
            case 1: {
                // Garante liberação antes de nova alocação
                liberar_matriz_continua(&m_continua);
                liberar_matriz_ponteiros(&m_ponteiros, linhas);

                long input_l, input_c;
                printf("Informe o numero de linhas: ");
                scanf("%ld", &input_l);
                printf("Informe o numero de colunas: ");
                scanf("%ld", &input_c);

                if (input_l <= 0 || input_c <= 0) {
                    printf("Erro: Dimensoes devem ser inteiros positivos maiores que zero.\n");
                    linhas = 0;
                    colunas = 0;
                    break;
                }

                linhas = (size_t)input_l;
                colunas = (size_t)input_c;

                m_continua = criar_matriz_continua(linhas, colunas);
                m_ponteiros = criar_matriz_ponteiros(linhas, colunas);

                if (m_continua && m_ponteiros) {
                    printf("Sucesso: Ambas as matrizes foram alocadas!\n");
                } else {
                    printf("Erro ao alocar uma ou ambas as matrizes.\n");
                }
                break;
            }
            case 2:
                if (!m_continua || !m_ponteiros) {
                    printf("Erro: Aloque as matrizes primeiro (Opcao 1).\n");
                } else {
                    preencher_matriz_continua(m_continua, linhas, colunas);
                    preencher_matriz_ponteiros(m_ponteiros, linhas, colunas);
                    printf("Matrizes preenchidas com sucesso!\n");
                }
                break;

            case 3:
                exibir_matriz_continua(m_continua, linhas, colunas);
                exibir_matriz_ponteiros(m_ponteiros, linhas, colunas);
                break;

            case 4:
                liberar_matriz_continua(&m_continua);
                liberar_matriz_ponteiros(&m_ponteiros, linhas);
                linhas = 0;
                colunas = 0;
                printf("Memoria das matrizes liberada com sucesso.\n");
                break;

            case 0:
                liberar_matriz_continua(&m_continua);
                liberar_matriz_ponteiros(&m_ponteiros, linhas);
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_EXIBICAO 60


typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_STRING
} TipoDado;

// Estrutura do Jogador
typedef struct {
    char nomeExibicao[TAMANHO_EXIBICAO];
    int nivel;
    float pontuacao;
} Jogador;


void exibirDadoDiagnostico(void *ponteiroGenerico, TipoDado tipo);

int main() {
    int quantidade = 0;
    Jogador *jogadores = NULL; // Inicializamos com NULL por segurança

    printf("===========================================\n");
    printf("   DIAGNOSTICO E CADASTRO DE JOGADORES     \n");
    printf("===========================================\n\n");

    printf("Digite a quantidade de jogadores para alocar: ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Erro: Quantidade invalida inserida!\n");
        
        return 1; 
    }

    // Limpa o buffer do teclado
    while (getchar() != '\n');

    // REQUISITO: Alocação dinâmica de memória
    jogadores = (Jogador*) malloc(quantidade * sizeof(*jogadores));

    // REQUISITO: Tratar falhas de alocação de memória
    if (jogadores == NULL) {
        printf("Erro critico: Falha ao alocar memoria RAM!\n");
        return 1; // Encerra com segurança sem acessar o ponteiro
    }

    // Preenchendo dados de exemplo para o diagnóstico
    printf("\n--- Preenchendo Dados do Jogador 1 ---\n");
    strcpy(jogadores[0].nomeExibicao, "PixelKnight [Equipe Raylib]");
    jogadores[0].nivel = 15;
    jogadores[0].pontuacao = 2550.50f;

    // =================================================================
    // TESTE DA FUNÇÃO GENÉRICA DE DIAGNÓSTICO (void*)
    // REQUISITO: Aceitar ao menos dois tipos de dado na função genérica
    // =================================================================
    printf("\n===========================================\n");
    printf("    FERRAMENTA DE DIAGNOSTICO DE DADOS     \n");
    printf("===========================================\n");

    printf("Nome do Jogador : ");
    exibirDadoDiagnostico(jogadores[0].nomeExibicao, TIPO_STRING);

    printf("Nivel do Jogador: ");
    exibirDadoDiagnostico(&jogadores[0].nivel, TIPO_INT);

    printf("Pontuacao      : ");
    exibirDadoDiagnostico(&jogadores[0].pontuacao, TIPO_FLOAT);


    // =================================================================
    // REQUISITO: REVISÃO DO FLUXO DE ENCERRAMENTO
    // =================================================================
    printf("\n===========================================\n");
    printf("      ENCERRAMENTO SEGURO DO CADASTRO      \n");
    printf("===========================================\n");

    // REQUISITO: Tratar saída verificando se o ponteiro é válido antes de liberar
    if (jogadores != NULL) {
        // REQUISITO: Chamar free exatamente uma vez para o bloco alocado
        free(jogadores);
        
        // REQUISITO: Atribuir NULL ao ponteiro liberado
        jogadores = NULL;
        
        printf("Memoria dos jogadores liberada com sucesso!\n");
    }

    // REQUISITO: Impedir novos acessos por ponteiros já liberados
    if (jogadores == NULL) {
        printf("Confirmacao: O ponteiro agora aponta para NULL e esta protegido contra acessos indevidos.\n");
    }

    return 0;
}

// =================================================================
// IMPLEMENTAÇÃO DA FUNÇÃO GENÉRICA DE DIAGNÓSTICO
// =================================================================
void exibirDadoDiagnostico(void *ponteiroGenerico, TipoDado tipo) {
    // REQUISITO: Tratar saídas antecipadas se o ponteiro for nulo
    if (ponteiroGenerico == NULL) {
        printf("[Dado Nulo]\n");
        return;
    }

    // REQUISITO: Converter o void* para o tipo correto antes da indireção
    // REQUISITO: Não tentar descobrir automaticamente o tipo (usamos a flag 'tipo')
    switch (tipo) {
        case TIPO_INT: {
            // Converte void* para int* e depois pega o valor com o '*' na frente
            int valorInt = *(int*)ponteiroGenerico;
            printf("%d\n", valorInt);
            break;
        }
        case TIPO_FLOAT: {
            // Converte void* para float* e obtém o valor
            float valorFloat = *(float*)ponteiroGenerico;
            printf("%.2f\n", valorFloat);
            break;
        }
        case TIPO_STRING: {
            // Converte void* para char* para imprimir a string
            char *valorString = (char*)ponteiroGenerico;
            printf("%s\n", valorString);
            break;
        }
        default:
            printf("Tipo de dado nao reconhecido!\n");
            break;
    }
}

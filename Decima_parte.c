#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define TAMANHO_NOME 50
#define TAMANHO_EQUIPE 20
#define TAMANHO_EXIBICAO 75


typedef struct {
    char nomeExibicao[TAMANHO_EXIBICAO];
} Jogador;

int main() {
    int quantidade;

    printf("===========================================\n");
    printf("   SISTEMA DE CADASTRO DINAMICO DE EQUIPE  \n");
    printf("===========================================\n\n");

    
    printf("Quantos jogadores deseja cadastrar nesta equipe? ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Erro: Quantidade invalida de jogadores!\n");
        return 1;
    }
    

    while (getchar() != '\n');


    
    Jogador *jogadores = malloc(quantidade * sizeof(*jogadores));

    // 3. REQUISITO: Verificar o retorno do malloc
    if (jogadores == NULL) {
        printf("Erro critico: Falha ao alocar memoria na RAM!\n");
        printf("A operacao foi encerrada com seguranca sem acessar o ponteiro.\n");
        return 1; // Encerra o programa sem tentar acessar a memória
    }

    printf("\nMemoria alocada com sucesso para %d jogador(es)!\n\n", quantidade);

    // 4. REQUISITO: Preencher somente posições válidas
    for (int i = 0; i < quantidade; i++) {
        char apelido[TAMANHO_NOME];
        char equipe[] = " [Equipe Raylib]";

        printf("--- Cadastrando Jogador %d ---\n", i + 1);
        printf("Digite o apelido do jogador: ");
        fgets(apelido, sizeof(apelido), stdin);
        apelido[strcspn(apelido, "\n")] = '\0'; // Remove a quebra de linha

        // Verifica capacidade do destino antes de copiar/concatenar
        size_t tamanhoNecessario = strlen(apelido) + strlen(equipe) + 1;
        
        if (tamanhoNecessario <= sizeof(jogadores[i].nomeExibicao)) {
            strcpy(jogadores[i].nomeExibicao, apelido);
            strcat(jogadores[i].nomeExibicao, equipe);
        } else {
            printf("Aviso: Nome muito longo! Usando nome padrao.\n");
            strcpy(jogadores[i].nomeExibicao, "JogadorAnonimo [Equipe Raylib]");
        }
    }

    // REQUISITO: Exibir somente posições válidas
    printf("\n===========================================\n");
    printf("      LISTA DE JOGADORES DA EQUIPE         \n");
    printf("===========================================\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID [%d]: %s\n", i + 1, jogadores[i].nomeExibicao);
    }

    // 5. REQUISITO: Liberar o bloco quando ele não for mais necessário
    free(jogadores);
    jogadores = NULL; // Boa prática em jogos: anular o ponteiro após o free!

    printf("\nMemoria liberada com sucesso. Fim da execucao.\n");

    return 0;
}

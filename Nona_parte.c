#include <stdio.h>
#include <string.h>

#define LINHAS 5
#define COLUNAS 5
#define LIVRE '.'  

// --- PROTÓTIPOS DAS FUNÇÕES ---
void inicializarMapa(char mapa[LINHAS][COLUNAS]);
void exibirMapa(char mapa[LINHAS][COLUNAS]);
int validarCoordenadas(int linha, int coluna);
int posicionarJogador(char mapa[LINHAS][COLUNAS], int linha, int coluna, char idJogador);
int removerJogador(char mapa[LINHAS][COLUNAS], int linha, int coluna);
int reposicionarJogador(char mapa[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

int main() {
    // Declarando a matriz do mapa do jogo
    char mapa[LINHAS][COLUNAS];

    // 1. REQUISITO: Inicializar a matriz antes do primeiro uso
    inicializarMapa(mapa);

    printf("=== MAPA INICIAL DO JOGO ===\n");
    exibirMapa(mapa);

    // 2. REQUISITO: Posicionar jogadores e validar coordenadas/ocupacao
    printf("\n--- Posicionando Jogadores ---\n");
    posicionarJogador(mapa, 0, 0, 'P'); // 'P' para Player 1
    posicionarJogador(mapa, 2, 3, 'K'); // 'K' para Knight
    posicionarJogador(mapa, 4, 4, 'M'); // 'M' para Mage

    // Tentar posicionar em lugar ocupado
    posicionarJogador(mapa, 0, 0, 'X'); 

    // Tentar posicionar fora do mapa (Coordenada inválida)
    posicionarJogador(mapa, 10, -1, 'Z'); 

    // 3. REQUISITO: Imprimir o mapa em formato legivel
    printf("\n=== MAPA COM JOGADORES ===\n");
    exibirMapa(mapa);

    // 4. REQUISITO: Permitir reposicionar um jogador cadastrado
    printf("\n--- Mover Jogador 'P' de (0,0) para (1,2) ---\n");
    reposicionarJogador(mapa, 0, 0, 1, 2);

    printf("\n=== MAPA APOS MOVER ===\n");
    exibirMapa(mapa);

    // 5. REQUISITO: Remover uma posição
    printf("\n--- Removendo Jogador da posicao (2,3) ---\n");
    removerJogador(mapa, 2, 3);

    printf("\n=== MAPA FINAL ===\n");
    exibirMapa(mapa);

    return 0;
}

// =================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
// =================================================================

// Preenche todas as células da matriz com o símbolo de LIVRE ('.')
void inicializarMapa(char mapa[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            mapa[i][j] = LIVRE;
        }
    }
}

// Imprime a matriz no terminal de forma organizada e legível
void exibirMapa(char mapa[LINHAS][COLUNAS]) {
    // Imprime o cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Imprime as linhas com o número da linha no início
    for (int i = 0; i < LINHAS; i++) {
        printf("%d  ", i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}

// REQUISITO: Nenhuma célula poderá ser acessada antes de validar a linha e a coluna
int validarCoordenadas(int linha, int coluna) {
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        return 1; // Coordenada válida
    }
    return 0; // Coordenada fora do mapa
}

// Posiciona um jogador se a coordenada for válida e a célula estiver livre
int posicionarJogador(char mapa[LINHAS][COLUNAS], int linha, int coluna, char idJogador) {
    if (!validarCoordenadas(linha, coluna)) {
        printf("Erro: Coordenadas (%d, %d) fora do mapa!\n", linha, coluna);
        return 0;
    }

    if (mapa[linha][coluna] != LIVRE) {
        printf("Erro: A posicao (%d, %d) ja esta ocupada por '%c'!\n", linha, coluna, mapa[linha][coluna]);
        return 0;
    }

    mapa[linha][coluna] = idJogador;
    printf("Jogador '%c' posicionado em (%d, %d) com sucesso.\n", idJogador, linha, coluna);
    return 1;
}

// Remove o conteúdo de uma célula e a torna livre novamente
int removerJogador(char mapa[LINHAS][COLUNAS], int linha, int coluna) {
    if (!validarCoordenadas(linha, coluna)) {
        printf("Erro: Coordenadas (%d, %d) fora do mapa!\n", linha, coluna);
        return 0;
    }

    if (mapa[linha][coluna] == LIVRE) {
        printf("Aviso: A posicao (%d, %d) ja esta livre.\n", linha, coluna);
        return 0;
    }

    mapa[linha][coluna] = LIVRE;
    printf("Posicao (%d, %d) limpa com sucesso.\n", linha, coluna);
    return 1;
}

// REQUISITO: Reposicionar um jogador cadastrado
int reposicionarJogador(char mapa[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // 1. Valida origem e destino
    if (!validarCoordenadas(linhaOrigem, colunaOrigem) || !validarCoordenadas(linhaDestino, colunaDestino)) {
        printf("Erro: Coordenadas de origem ou destino invalidas!\n");
        return 0;
    }

    // 2. Verifica se existe alguém na origem para mover
    if (mapa[linhaOrigem][colunaOrigem] == LIVRE) {
        printf("Erro: Nao ha nenhum jogador na posicao de origem (%d, %d)!\n", linhaOrigem, colunaOrigem);
        return 0;
    }

    // 3. Verifica se o destino está livre
    if (mapa[linhaDestino][colunaDestino] != LIVRE) {
        printf("Erro: O destino (%d, %d) ja esta ocupado!\n", linhaDestino, colunaDestino);
        return 0;
    }

    // 4. Move o jogador: guarda a identificação, limpa a origem e coloca no destino
    char idJogador = mapa[linhaOrigem][colunaOrigem];
    mapa[linhaOrigem][colunaOrigem] = LIVRE;
    mapa[linhaDestino][colunaDestino] = idJogador;

    printf("Jogador '%c' movido de (%d, %d) para (%d, %d)!\n", idJogador, linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
    return 1;
}
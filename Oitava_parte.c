#include<stdio.h>
#include<string.h>

#define TAMANHO 50
#define TAMANHO_PUFFER 30
#define TAMANHO_SENHA 20
#define TAMANHO_EXIBICAO 60
#define MAX_JOGADORES 3
 int main (){
    char nome [TAMANHO];
    char apelido [TAMANHO_PUFFER];
    char senha [TAMANHO_SENHA];
    char confirmação [TAMANHO_SENHA];

    printf ("Digite o seu nome:");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf ("Digite o seu apelido: (digite entre 3 a 10 caracteres)");
    fgets(apelido, sizeof(apelido), stdin);
    apelido[strcspn(apelido, "\n")] = '\0';
    int tamanho= strlen (apelido);
    if(tamanho<3){
        printf ("Apelido muito curto!\n");
    }else if (tamanho>10){
        printf ("Apelido muito longo!\n");
    }else{
        printf ("Apelido válido!\n");
    }

    printf ("Digite a sua senha: (digite entre 6 a 12 caracteres)");
    fgets (senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    printf("Confirme a sua senha: ");
    fgets (confirmação, sizeof(confirmação), stdin);
    confirmação[strcspn(confirmação, "\n")] = '\0';

    if (strcmp(senha, confirmação) == 0){
        printf ("Senha confirmada com sucesso!\n");
    }else{
        printf ("As senhas não coincidem!\n");
    }
// --- PARTE 2: MONTAGEM DO NOME DE EXIBICAO ---
    char nome_equipe[] = " [Equipe Raylib]";
    char nome_exibicao[TAMANHO_EXIBICAO];

    // Verificacao de segurança contra Buffer Overflow
    size_t tamanho_necessario = strlen(apelido) + strlen(nome_equipe) + 1;

    if (tamanho_necessario <= sizeof(nome_exibicao)) {
        strcpy(nome_exibicao, apelido);
        strcat(nome_exibicao, nome_equipe);
        printf("Nome de exibicao gerado: %s\n\n", nome_exibicao);
    } else {
        printf("Erro: Vetor de destino nao possui espaco suficiente!\n");
        return 1;
    }

    // --- PARTE 3: LISTA E BUSCA DE JOGADORES ---
    char jogadores[MAX_JOGADORES][TAMANHO_EXIBICAO] = {
        "PixelKnight [Equipe Raylib]",
        "ShadowNinja [Equipe Raylib]",
        "CyberMage [Equipe Raylib]",
        "StarLord [Equipe Raylib]",
        "" // A quinta posição recebe o novo jogador
    };

    // Insere o jogador cadastrado na ultima vaga da lista
    strcpy(jogadores[4], nome_exibicao);

    // Listagem no terminal
    printf("=== LISTA DE JOGADORES CADASTRADOS ===\n");
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("Posicao %d: %s\n", i + 1, jogadores[i]);
    }
    printf("\n");

    // Busca exata com strcmp
    char busca[TAMANHO_EXIBICAO];
    printf("Digite o nome exato do jogador que deseja buscar: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < MAX_JOGADORES; i++) {
        if (strcmp(jogadores[i], busca) == 0) {
            printf("Sucesso! Jogador '%s' encontrado na posicao %d.\n", busca, i + 1);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Jogador '%s' nao foi encontrado na lista.\n", busca);
    }

    return 0;

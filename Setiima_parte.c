#include<stdio.h>
#include<string.h>

#define TAMANHO 50
#define TAMANHO_PUFFER 30
#define TAMANHO_SENHA 20
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
    return 0;
}


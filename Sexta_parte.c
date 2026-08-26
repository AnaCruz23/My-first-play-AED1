
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char nome[30];
    int quantidade;
} Item;
typedef struct{
    int vida;
    int pontuacao;
} jogador;
void ExibirInventarioNotacaoVetor(Item*inventario[], int tamanho){
    for (int i=0; i<tamanho; i++){
       printf ("Item %d: %s| Quantidade: %d (endereço guardado: %p)\n", i+1, inventario[i]->nome, inventario[i]->quantidade, (void*)inventario[i]);   
    }
}
void AlterarItemAritmeticaPonteiros(Item*inventario[],int tamanho){
   int indice, nova_quantidade;
   printf ("\n=== ALTERAR ITEM===\n");
   printf ("Digite o número do item( 1 a %d): ", tamanho);
   scanf ("%d", &indice);

   if (indice < 1 || indice > tamanho){
      printf ("Índice inválido! \n");
      return;
   }
   int i= indice -1;
   printf ("Digite a nova quantidade de %s: ", (*(inventario + i))->nome);
   scanf ("%d", &nova_quantidade);
   (*(inventario+i))->quantidade= nova_quantidade;
   printf ("Item alterado com sucesso!\n");
}
int main (){
    Item espada= {"Espada de Aço", 1};
    Item escudo= {"Escudo de Madeira", 1};
    Item porcao= {"Porção de Vida", 5};

    Item* inventario[3]= {&espada, &escudo, &porcao};
    int TotalItens=3;

    jogador jogador ={100,0}; // Vida: 100, pontuação: 0
    int opcao;
    do{
        printf ("\n=== MENU DO JOGO===\n");
        printf ("1. Ver status de vida e pontuação \n");
        printf ("2. Ver mapa\n");
        printf ("3. Consultar Inventário (notação do vetor)\n");
        printf ("4. Alterar item (aritmética de ponteiros)\n");
        printf ("5. Alterar vida/pontuação\n");
        printf ("0. Sair\n");
        printf ("Escolha uma opção: ");
        scanf ("%d",&opcao);

        switch (opcao){
            case 1:
                printf ("\n [STATUS] Vida: %d| Pontuação: %d\n", jogador.vida, jogador.pontuacao);
                break;
            case 2:
                 printf ("\n [MAPA] Você está na Floresta Antiga (X:12, Y:45). \n");
                 break;
            case 3:
                ExibirInventarioNotacaoVetor (inventario, TotalItens);
                break;
            case 4:
                AlterarItemAritmeticaPonteiros (inventario, TotalItens);
                break;
            case 5:
                printf ("\n Digite a nova vida:");
                scanf ("%d", &jogador.vida);
                printf ("Digite a nova pontuação: ");
                scanf ("%d", &jogador.pontuacao);
                break;
            case 0:
                printf ("\nSaindo do simulador...\n");
                break;
            default:
                printf ("\nOpção inválida!\n");
        }
    }while (opcao!=0);
return 0;
}


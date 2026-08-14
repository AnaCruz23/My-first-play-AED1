#include <stdio.h>

int main(){
int vida=100;
int *ponteiro_vida=&vida;
int tesouro=0;
int *ponteiro_tesouro=&tesouro;
printf ("=== ESTADO INICIAL DO JOGO ===\n");
printf("vida:%d \n",*ponteiro_vida);
printf ("tesouro:%d \n",*ponteiro_tesouro);
printf ("=== APARECIMENTO DE DANOS=== \n");
*ponteiro_vida=*ponteiro_vida-20;
printf(" O JOGADOR SOFREU UM DANO! MENOS 20 DE VIDA! \n", vida);
printf ("======================== \n");
printf (" === RESTAURAÇÃO DE VIDA!=== \n");
*ponteiro_vida=*ponteiro_vida+20;
printf (" O JOGADOR CUMPRIU O PRAZO DO MISSÃO! RECEBA MAIS 20 DE VIDA! \n", vida);
printf ("======================== \n");
printf ("=== APARECIMENTO DE TESOURO === \n");
*ponteiro_tesouro=1;
printf (" O JOGADOR ENCONTROU UM TESOURO! \n", tesouro);
printf ("======================== \n");
printf ("=== FIM DE JOGO===");
printf (" VIDA FINAL DO JOGADOR: %d \n", vida);
printf (" TESOURO FINAL DO JOGADOR: %d \n", tesouro==1?"SIM":"NÃO");
return 0;
}
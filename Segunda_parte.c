#include <stdio.h>
void aplicar_dano (int *vida, int dano){
    if (vida==NULL) return;
    *vida= *vida-dano;
    printf (" O jogador sofreu %d de dano \n", dano);
    printf ("alterando no endreço: %p | vida: %d\n\n", (void*)vida,*vida);
    
}
void restaurar_vida(int *vida){
    if (vida==NULL) return;
    *vida=*vida+20;
    printf (" O jogador cumpriu o prazo da missão! +20 de vida!\n");
    printf ("Alterando no endereço: %p | Vida: %d\n\n",(void*)vida,*vida);
}
void aplicar_pontuacao_dupla (int*pontuacao){
    if (pontuacao==NULL) return;
    *pontuacao=*pontuacao*2;
    printf ("O jogador duplicou sua força\n");
    printf ( "endereço: %p |Pontos: %d\n\n",(void*)pontuacao, *pontuacao);
}
void ativar_tesouro(int*tesouro){
    if(tesouro==NULL) return;
    *tesouro=1;
    printf ("Você encontrou um tesouro!\n");
    printf ("Endereço: %p| Estado:%d\n\n", (void*)tesouro,*tesouro);
}
int main(){
    int vida=100;
    int pontuacao=50;
    int tesouro=0;

    int *ptr_vida=&vida;
    int *ptr_pontuacao=&pontuacao;
    int *ptr_tesouro=&tesouro;

    printf("===ESTADO INICIAL DO JOGO===\n");
    printf("Vida inicial: %d | Endereço:%p \n", vida, (void*)&vida);
    printf ("pontuação inicial:%d |Endereço: %p\n",pontuacao, (void*)&pontuacao);
    printf ("Tesouro inicial: %d | Endreço: %p\n", tesouro, (void*)&tesouro);
    aplicar_dano(ptr_vida,20);
    restaurar_vida(ptr_vida);
    aplicar_pontuacao_dupla(ptr_pontuacao);
    ativar_tesouro(ptr_tesouro);
    printf ("=== FIM DE JOGO ===\n");
    printf ("Vida final: %d | Endereço: %p\n", vida, (void*)&vida);
    printf ("Pontuação final: %d | Endereço: %p\n", pontuacao, (void*)&pontuacao);
    printf ("Tesouro final: %d | Endereço: %p\n", tesouro, (void*)&tesouro);
    return 0;
    }
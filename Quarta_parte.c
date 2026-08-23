#include<stdio.h>
#define TAMANHO_MIN 1
#define TAMANHO_MAX 20
#define VALOR_MIN 0
#define VALOR_MAX 100

int ler_mapa (int *mapa, int tamanho){
    if (mapa==NULL){
        printf ("Mapa inválido\n");
        return 0;
    }
    if(tamanho<TAMANHO_MIN || tamanho>TAMANHO_MAX){
        printf ("Tamanho do mapa inválido( permitido apenas entre %d e %d\n", TAMANHO_MIN, TAMANHO_MAX);
        return 0;
    }
    printf ("\n====Leitura do Mapa====\n");
        for (int i=0; i<tamanho; i++){
            int valor;
        printf ("Informe o valor da plataforma %d: ", i);
        scanf ("%d", &valor);
        if (valor<VALOR_MIN || valor>VALOR_MAX){
            printf ("Valor inválido (permitido apenas entre %d e %d)\n", VALOR_MIN, VALOR_MAX);
            return 0;
        }
        *(mapa+i)=valor;
        }
        return 1;
     }
    
void mostrar_mapa (const int *mapa,int tamanho){
if (mapa==NULL || tamanho< TAMANHO_MIN || tamanho> TAMANHO_MAX){
    printf ("Mapa inválido\n");
    return;
}
    printf ("\n=====EXIBIR MAPA=====\n"); 
    for (int i=0; i<tamanho; i++){
    printf ("%d", *(mapa+i));
    }
}
void explorar_mapa (const int *mapa, int tamanho){
   if (mapa==NULL){
return;
   }
     printf ("\n=== EXPLORAÇÃO COMPLETA DA FASE===\n");
    for(int i=0;i<tamanho;i++){// plataforma=degrau(altura da onde o jogador está)
        int altura=*(mapa+i);
        printf ("Jogador pisou na plataforma %d (altura:%d)\n",i, altura);
    }
    printf ("\n====FIM DA FASE====\n");
}
int main(){
    int mapa[TAMANHO_MAX];
    int tamanho;
    printf ("Digite o tamanho do mapa: Só pode ser entre [%d] e {%d]\n", TAMANHO_MIN, TAMANHO_MAX);
    scanf ("%d", &tamanho);
    if (ler_mapa(mapa, tamanho)==0){
        printf ("Erro ao ler o mapa\n");
        return 1;
    }
mostrar_mapa(mapa, tamanho);
explorar_mapa(mapa, tamanho);
return 0;
}

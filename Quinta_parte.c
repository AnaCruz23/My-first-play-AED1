
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
    printf (" %d ", *(mapa+i));
    }
}
void explorar_mapa(const int *mapa, int tamanho){
    if( mapa==NULL || tamanho< TAMANHO_MIN || tamanho> TAMANHO_MAX){
        return;
    }
    const int*cursor=mapa; //ponteiro auxiliar
    const int *fim=mapa+tamanho; // calculo o endereço imediatamente após o último elemento
    int pontuacao_total=0;
    int posicao_logica=0;
    printf ("\n=== INICIANDO A EXPLORAÇÃO COM O CURSOR===\n");
    while (cursor<fim){
        int valor_atual=*cursor;// valor_atual aponta para o cursor
        pontuacao_total+= valor_atual;// atualização da pontuação acumulada;
 printf ("Cursor do endereço %p -> Plataforma %d | Valor: %d | Pontos acumulados: %d\n", (void*)cursor, posicao_logica, valor_atual, pontuacao_total);
cursor ++; // incremento do ponteiro pula 4 bytes
posicao_logica++; // incremento de uma variável comum
    }
    printf ("\n=== RESUMO DO PERCURSO===\n");
    printf ("Total de plataformas exploradas: %d\n", tamanho);
    printf ("pontuação acumulada: %d\n", pontuacao_total);
    printf ("Status:o cursor atingiu o limite final %p com sucesso!", (void*)fim);
    
}
int main(){
    int mapa[TAMANHO_MAX];
    int tamanho;
    printf ("Digite o tamanho do mapa: Só pode ser entre [%d] e [%d]\n", TAMANHO_MIN, TAMANHO_MAX);
    scanf ("%d", &tamanho);
    if (ler_mapa(mapa, tamanho)==0){
        printf ("Erro ao ler o mapa\n");
        return 1;
    }
    mostrar_mapa(mapa, tamanho);
    explorar_mapa(mapa, tamanho);
    return 0;
}
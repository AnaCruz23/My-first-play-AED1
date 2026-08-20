#include<stdio.h>
int main(){
    int v[5]={-20,-10,5,10,20};
    int pontos=0;
    int *ptr_pontos=&pontos;
    int altura=0;
    for(int i=0;i<5;i++){
        printf ("Índice: %d|Endereço: %p|Conteúdo: %d\n",i,(void*)(v+i), *(v+i));
        pontos+=*(v+i);
        altura+=*(v+i);
    }
    // O deslocamento utilizado respeita o ponteiro, pois ao somar +1, o computador entende que o valor 
    //inteiro ocupa 4 bytes, então o endereço do próximo elemento do vetor será o endereço atual + 4 bytes.
    printf ("\n Pontuação total: %d\n", pontos);
    printf ("Altura total: %d\n", altura);
    return 0;

}
// dia 05/04

#include <stdio.h>
#define TAM 50


void max(int *v, int *n){
    int maior = 0;
    for(int i = 0; i<*n; i++){
        if(*(v+i) > (maior)) maior = *(v+i); //compara o valor atual do vetor com o maior coletado
    }
    *n = maior; //substitui o valor 
}


int main(){
    int t, n; //t = tamanho do vetor, n = n-esimo numero
    
    scanf("%d %d", &t, &n);


    int vet[TAM];
    for(int i = 0; i<t; i++) scanf("%d", &vet[i]); //pega os elementos do vetor
    

    max(&vet[0],&n); //chamada da funcao

    printf("%d", *n); //print da variável alterada
    
    return 0;
}

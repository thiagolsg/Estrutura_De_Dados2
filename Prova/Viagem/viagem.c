#include <stdio.h>
#define Max 1000000
int main(){

int count_dias=0;
int qtd;
int maior;
int menor;
int restaurante[Max];
int notas[Max];
while(scanf("%d",&qtd)!=EOF){
    count_dias++;
    
    int j;

    for(int i = 0; i < qtd;i++){
        scanf("%d",&restaurante[i]);
        scanf("%d",&notas[i]);
        if(i==0){
            maior = notas[i];
            menor = restaurante[i];
        }
        if(notas[i] > maior){
            maior=notas[i];
            menor= restaurante[i];
            j = i;
        }
        else if(notas[i] == maior){
            if(restaurante[i] < menor){
               menor = restaurante[i];
            }
        }    
            
        }
        printf("Dia %d\n%d\n\n",count_dias,menor);
        j = 0;

    }


    return 0;
}
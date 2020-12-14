#include <stdio.h>
#include <stdlib.h>

int main (){
    int qtd;
    int vetconta[100];
    int soma;
    int somareal = 0;
    

    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){
        scanf("%d",&vetconta[i]);
       
    }

    for (int j=0;j<qtd;j++){
        somareal = somareal + vetconta[j];
    }

    scanf("%d",&soma);

    if(somareal == soma){
        printf("Acertou\n");

    }
    else {
        printf("Errou\n");
    }

    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 1000001
#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define comp(A,B) (key(A)!= key(B))

int hT (int x){
    return x % Max;
}

int main (){
    int vet1[Max] = {};
    int vet2[Max] = {};
    int freq;
    int mfreq = 0;
    int qtd;
    int count = 0;
    scanf ("%d", &qtd);
    
    for(int i=0;qtd!=0;i++) {
        
        while(count<qtd){
            
            scanf ("%d", &freq);
        
            if(comp(vet1[hT(freq)],0)){
                vet2[hT(freq)] += 1;
                if(less(mfreq,vet2[hT(freq)])) mfreq = vet1[hT(freq)];          
            }
            else{
                vet1[hT(freq)] = freq; vet2[hT(freq)] += 1;
            }
            count++;
        }
        count = 0;
        memset(vet1, 0, sizeof(vet1)); 
        memset(vet2, 0, sizeof(vet2));
        
        printf ("%d\n", mfreq);
        
        mfreq = 0;
        scanf ("%d", &qtd);
    }
    return 0;
}


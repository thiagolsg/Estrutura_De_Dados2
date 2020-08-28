#include <stdio.h>
#include <stdlib.h>


#define key(a) (a)

#define less(a ,b) (key(a) < key(b))

#define exch(a, b) {int tmp = a; a = b; b = tmp;}

#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}
 

void insertionSort(int *v, int l , int r){
    for(int i = r; i > l; i--){
        cmpexch(v[i-1],v[i]);
    }
    for(int i = l+2; i <= r;i++){
        int j = i;
        int tmp = v[j];

        while (less(tmp,v[j-1]))
        {
            v[j] = v[j-1]; 
            
            j--;
            
            
        }
        v[j] = tmp;
    }
}



int main(){
    int a;
    int *vet = malloc(50000 * sizeof(int));
    int count = 0;
    int i;
    while(scanf("%d",&a) != EOF){
        vet[count] = a;
        count++;
     }

    insertionSort(vet,0,count-1);

    for(i = 0; i < count-1 ; i++){
        printf("%d ",vet[i]);
    }

    printf("%d\n",vet[i]);

    free(vet);

    return 0;
}
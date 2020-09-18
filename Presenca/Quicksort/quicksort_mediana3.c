#include  <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a, b) {int tmp = a; a = b; b = tmp;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}


int separa (int *v, int l, int r){

    int init = v[r];
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k], init)){
            exch (v[k], v[j]);
            j++;
        }
        exch (v[j], v[r]);

    return j;
}


void quicksort(int *v,int l,int r){
    int j;

    if(r<=l) return;

    cmpexch(v[(l+r)/2],v[r])
    cmpexch(v[l],v[(l+r)/2])
    cmpexch(v[r],v[(l+r)/2])

    j = separa(v,l,r);
    
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);
}

int main(){


int l,r;
int tam;
int count=0;

scanf("%d",&tam);

int *v = malloc(tam *sizeof(int));

for(int i=0;i<tam;i++){

    scanf("%d",&v[i]);

}

quicksort(v,0,tam-1);

for(int i=0;i<tam-1;i++){

    printf("%d ",v[i]);
    count++;
}

printf("%d\n",v[count]);

    return 0;
}
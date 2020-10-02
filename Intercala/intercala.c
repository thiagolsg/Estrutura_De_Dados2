#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define lesseq(A,B) ((A) <= (B))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}


void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}



int main (){

    int size_vet, num, i = 0, final_size_vet = 0, count = 0;
    int *vet = malloc (1000000 * sizeof(int));
    

    while (count < 8){
        scanf("%d", &size_vet);
        count ++;
        final_size_vet += size_vet;

        for (int j = 0; j < size_vet; j++){
            scanf ("%d", &num);
            vet[i] = num;
            i++;
        }  
    }

    mergesort (vet, 0, final_size_vet-1);

    for (int k = 0; k < final_size_vet; k++){
        if (k == final_size_vet-1)
            printf ("%d\n", vet[k]);
        else
            printf ("%d ", vet[k]);
    }

    return 0;
}


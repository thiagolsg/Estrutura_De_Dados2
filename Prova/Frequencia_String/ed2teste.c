#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 128
#define key(A) (A)
//#define less(A,B) (key(A)<key(B))
#define lesseq(A,B) ((A) <= (B))
#define comp(A,B) (key(A)!= key(B))
#define value_int(A) ((int) A)
#define exch(a, b) {int tmp = a; a = b; b = tmp;}
//#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}



typedef struct hfreq{
    int ascii;
    int rep;
}hfreq;



void merge (hfreq *v, int l, int r1, int r2){

    hfreq *v2 = malloc (sizeof (hfreq) * (r2-l+1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2){
        if (lesseq(v[i].rep, v[j].rep))
            v2[k++] = v[i++];

        else
            v2[k++] = v[j++];
    }

    while (i <= r1)
        v2[k++] = v[i++];

    while (j <= r2)
        v2[k++] = v[j++];

    k = 0;

    for (i = l; i <= r2; i++)
        v[i] = v2[k++];

    free (v2);

}

void merge_sort (hfreq *v, int l, int r){

    if (l >= r) return;

    int meio = (r + l) / 2;
    merge_sort (v, l, meio);
    merge_sort (v, meio + 1, r);
    merge (v, l, meio, r);

}

// void selection_sort (hfreq *v, int l, int r){

//     for (int i = l; i < r; i++){
//         int min = i;
//         for (int j = i+1; j < r; j++){
//             if (v[j] < v[min])
//                 min = j;
//         }
//         exch (v[i], v[min]);
//         //exch (v[min].rep, v[i].rep);
//     }
// }


int hT (int x){
    return x % Max;
}



int main(){
    hfreq vetst[Max] = {};
    char vetchar[1000];
   //int count = 0
    while(scanf(" %s",vetchar)!=EOF){

       
        for(int i=0;vetchar[i]!='\0';i++){   
            if(!comp(vetst[hT(value_int(vetchar[i]))].ascii,0)){
                vetst[hT(value_int(vetchar[i]))].ascii = value_int(vetchar[i]);
                vetst[hT(value_int(vetchar[i]))].rep++;
            }
            else{
                vetst[hT(value_int(vetchar[i]))].rep++;
            }
            //count++;
        }

        merge_sort(vetst,0,Max);

        for(int j=0;j<Max;j++)
            if(vetst[j].ascii != 0 && vetst[j].rep!=0 )
              printf("%d %d\n",vetst[j].ascii,vetst[j].rep);
        



       // count = 0;
        memset(vetst, 0, sizeof(vetst)); 
        
        printf("\n");
            
    }





    return 0;
}
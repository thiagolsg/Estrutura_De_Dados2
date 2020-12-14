#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define maxV 1048577
item max =-1, min =__INT_MAX__;

typedef struct message
{
    item s;
    char c;
}m;

item hash (item n)
{
    return n%maxV;
}

item main (void)
{
    m *v=malloc(maxV * sizeof (m));
    for (item i=0;i<maxV;i++) v[i].s=-1;
    item k;
    char c;
    while (scanf (" %d", &k) != EOF){
        scanf (" %c", &c);
        v[hash(k)].s = k;
        v[hash(k)].c = c;
        if (k > max) max = k;
        if (k < min) min = k;
    }
    item i;
    for (i=min;i<=max;i++) printf ("%c", v[hash(i)].c);
    printf("\n");
    free (v);
    
    return 0;
}

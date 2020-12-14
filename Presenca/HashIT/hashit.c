#include <stdio.h>
#include <string.h>

#define N 0
#define DELL 1
#define FILL 2



typedef struct EntradaHash {
  int f;
  int hash;
  char s[20];
} EntradaHash;

typedef struct TabelaHash {
  int tam;
  EntradaHash entries[101];
} TabelaHash;

int funcao_hash(char *s) {
  long sum = 0;
  long i = 1;
  while(*s != '\0') {
    sum += (*s) * i;
    ++i;
    ++s;
  }
  return (19 * sum) % 101;
}

int procura_hash(TabelaHash *h, char *string) {
  int hash = funcao_hash(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entries[loc].f == N) return 0;
    if(h->entries[loc].f == DELL) continue;
    if(h->entries[loc].hash == hash && (strcmp(h->entries[loc].s, string) == 0)) {
      return 1;
    }
  }
  return 0;
}

void insere_hash(TabelaHash *h, char *string) {
  int hash = funcao_hash(string);
  int j;

  if (procura_hash(h, string) == 1) return;

  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entries[loc].f == N || h->entries[loc].f == DELL) {
      (h->tam)++;
      h->entries[loc].f = FILL;
      h->entries[loc].hash = hash;
      strcpy(h->entries[loc].s, string);
      break;
    }
  }
  return;
} 

void hash_table_delete(TabelaHash *h, char *string) {
  int hash = funcao_hash(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if(h->entries[loc].f == N) return;
    if(h->entries[loc].f == DELL) continue;
    if(h->entries[loc].hash == hash && (strcmp(h->entries[loc].s, string) == 0)) {
      h->entries[loc].f = DELL;
      (h->tam)--;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    TabelaHash hash;

    int i, j;
    for(i = 0; i < 101; ++i) {
      hash.entries[i].f = N;
    }
    hash.tam = 0;

    int n;
    scanf("%d", &n);

    char string[50];
    for(i = 0; i < n; ++i) {
      scanf("%s", string);
      if(string[0] == 'A') {
        
        insere_hash(&hash, string + 4);
      } else {
        
        hash_table_delete(&hash, string + 4);
      }
    }

    printf("%d\n", hash.tam);
    for(i = 0; i < 101; ++i) {
      if(hash.entries[i].f == FILL) {
        printf("%d:%s\n", i, hash.entries[i].s);
      }
    }
  }
  return 0;
}
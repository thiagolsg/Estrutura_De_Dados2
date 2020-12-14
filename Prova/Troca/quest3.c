#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 999999

typedef struct {
	int v, w;
} Edge;

typedef struct graph {
	int v, e;
	int **adj, **tc;
} Graph;

int pre[N];
int cnt = 0;
int conexos = 0;



int ** MATRIXInit(int l, int c, int p){
    int **matrix;
    matrix = malloc(l * sizeof(int *));
    for(int i=0; i < l; i++){
        matrix[i] = malloc(c * sizeof(int));
    }
    return matrix;
}


Graph* GRAPHinit(int v) {
	Graph *g = malloc(sizeof(g));
	g->v = v;
	g->e = 0;
	g->adj = MATRIXInit(v, v, 0);
	return g;
}


void GRAPHInsertE(Graph *g, Edge e, int D){
    int v = e.v;
    int w = e.w;
 
    if(g -> adj[v][w] == 0) g -> e++;
    
    if(D == 1) g -> adj[v][w] = 1;

    if(D == 2){
        g -> adj[v][w] = 1;
        g -> adj[w][v] = 1;
    }
}



void GRAPHSearch(Graph *g) {
    int count;
    Edge edge;
   
    for(count = 0; count < g -> v; count++){
      pre[count] = -1;
    }

    for(count = 0; count < g -> v; count++){
        if(pre[count] == -1){
            edge.v = count;
            edge.w = count;
            dfsR(g, edge);
            conexos++; 
        }
    }
}

void dfsR(Graph *G, Edge e) {
	int t, w = e.w;
	pre[w] = cnt++;
	for (t = 0; t < G->v; t++){
		if (G->adj[w][t] != 0)
			if (pre[t] == -1)
				dfsR(G, EDGE(w, t));
    }
}


Edge EDGE(int v, int w){
    Edge edge;
    edge.v = v;
    edge.w = w;
    return edge;
}


void GRAPHtc(Graph *G) {
	int i, s, t;
	G->tc = MATRIXInit(G->v, G->v, 0);
	
	for (s = 0; s < G->v; s++) {
		for (t = 0; t < G->v; t++) {
			G->tc[s][t] = G->adj[s][t];
		}
	}
	
	
	for (s = 0; s < G->v; s++) G->tc[s][s] = 1;
	
	for (i = 0; i < G->v; i++) {
		for (s = 0; s < G->v; s++) {
			if (G->tc[s][i] == 1){
				for (t = 0; t < G->v; t++) {
					if (G->tc[i][t] == 1) {
						G->tc[s][t] = 1;
					}
				}
            }
		}
	}
	
}

int GRAPHreach(Graph *G, int s, int t) {
	return G->tc[s][t];
};


int main() {
    int V, W, D, nV;
    int ida, volta;
    bool boolean = true; 
   
    scanf("%d",&nV);
    
    Graph *g = GRAPHinit(nV);
    
        while(boolean!=0){
        scanf("%d %d %d",&V, &W, &D);
        if(D != 0) GRAPHInsertE(g, EDGE(V,W), D);
        if(V == 0 && W == 0 && D == 0) boolean = false;
    }
    
    GRAPHtc(g);

        while(scanf("%d %d",&V,&W) != EOF){
            volta = GRAPHreach(g, W, V);
            ida = GRAPHreach(g, V, W);
            if(!(ida && volta )) printf("Impossibru\n"); 
            if(ida == 1 && volta == 0) printf("Apenas Ida\n"); 
            if(ida == 0 && volta == 1) printf("Apenas Volta\n"); 
            if(ida  && volta ) printf("Ida e Volta\n");
        }
      
    return 0;
}



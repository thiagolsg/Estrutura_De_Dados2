#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

typedef struct {
	int v;
	int w;
} Edge;

typedef struct graph {
	int v;
	int e;
	int **adj;
} Graph;

int pre[MAX];
int cnt = 0;
int conexos = 0;

Edge EDGE(int a, int b);
//typedef struct graph* Graph;
Graph* GRAPHinit(int a); 
void GRAPHInsertE(Graph *g, Edge);
void GRAPHRemoveE(Graph *g, Edge);
int GRAPHEdges(Edge[], Graph *g);
Graph GRAPHCopy(Graph);
void GRAPHDestroy(Graph *g);
void GRAPHSearch(Graph *g);
void dfsR(Graph *g, Edge e);

int ** MATRIXInit(int l, int c, int p){
    int **matrix;
    matrix = malloc(l * sizeof(int *));
    
    for(int i = 0; i < l; i++){
        matrix[i] = malloc(c * sizeof(int));
    }
    return matrix;
}



int main(){
    int vert, wvert, qtdv;
    Edge edge;
    
    scanf("%d", &qtdv);
    

    Graph *graph = GRAPHinit(qtdv);
    
    while(scanf("%d %d", &vert, &wvert) != EOF){
        
        GRAPHInsertE(graph, EDGE(vert,wvert));
    }
    
    GRAPHSearch(graph);
    
    printf("%d\n", conexos);

   
    return 0;

}



Graph* GRAPHinit(int v) {
	Graph *g = malloc(sizeof(g));
	g->v = v;
	g->e = 0;
	g->adj = MATRIXInit(v, v, 0);
	return g;
}

void GRAPHInsertE(Graph *g, Edge e) {
	int v = e.v;
	int w = e.w;
	if (g->adj[v][w] = 0) g->e++;
	g->adj[v][w] = 1;
	g->adj[w][v] = 1;
}

void GRAPHRemoveE(Graph *g, Edge e) {
	int v = e.v;
	int w = e.w;
	if (g->adj[v][w] == 1) g->e--;
	g->adj[v][w] = 0;
	g->adj[w][v] = 0;
}

int GRAPHEdges(Edge a[], Graph *g) {
	int v, w, E = 0;
	for (v = 0; v < g->v; v++)
		for (w = v+1; w < g->v; w++)
			if (g->adj[v][w] == 1)
				a[E++] = EDGE(v, w);
	return E;
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


Edge EDGE(int a, int b){
    Edge edge;
    edge.v = a;
    edge.w = b;
    return edge;
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

typedef struct {
	int v;
	int w;
} Edge;

typedef struct graph {
	int v;
	int e;
	int **adj;
    int **tc;
} Graph;

int pre[MAX];
int cnt = 0;
int conexos = 0;

Edge EDGE(int a, int b);
//typedef struct graph* Graph;
Graph* GRAPHinit(int a); 
void GRAPHInsertE(Graph *g, Edge, int d);
void GRAPHRemoveE(Graph *g, Edge);
int GRAPHEdges(Edge[], Graph *g);
Graph GRAPHCopy(Graph);
void GRAPHDestroy(Graph *g);
void GRAPHSearch(Graph *g);
void dfsR(Graph *g, Edge e);
void GRAPHtc(Graph *G);
int GRAPHreach(Graph *G, int s, int t);

int ** MATRIXInit(int l, int c, int p){
    int **matrix;
    matrix = malloc(l * sizeof(int *));
    for(int i=0; i < l; i++){
        matrix[i] = malloc(c * sizeof(int));
    }
    return matrix;
}


int main() {
    int vert, wvert,d, qtdv;
    int c1, c2;
   
    scanf("%d",&qtdv);
    
    Graph *graph = GRAPHinit(qtdv);
    
    
        for(int i = 0; ; i++){
        scanf("%d %d %d",&vert, &wvert, &d);
        
        if(d != 0) GRAPHInsertE(graph, EDGE(vert,wvert), d);
        
        
        if(vert == 0 && wvert == 0 && d == 0) break;
        
    }
    
    
    GRAPHtc(graph);

        while(scanf("%d %d",&vert,&wvert) != EOF){
            c1 = GRAPHreach(graph, vert, wvert);
            c2 = GRAPHreach(graph, wvert, vert);
           // printf("c1 = %d\n",c1);
           // printf("c2 = %d\n",c2);
            if(c1 == 1 && c2 == 1){
                printf("Ida e Volta\n"); 
            }
            else if(c1 == 1 && c2 == 0){
                printf("Apenas Ida\n"); 
            }
            else if(c2 == 1 && c1 == 0){
                printf("Apenas Volta\n"); 
            }
            else if(c1 == 0 && c2 == 0){
                printf("Impossibru\n"); 
            }
        }
      
    return 0;
}

Graph* GRAPHinit(int v) {
	Graph *g = malloc(sizeof(g));
	g->v = v;
	g->e = 0;
	g->adj = MATRIXInit(v, v, 0);
	return g;
}


void GRAPHInsertE(Graph *g, Edge e, int d){
 int v = e.v;
 int w = e.w;
 
    if(g -> adj[v][w] == 0) g -> e++;
    
    if(d == 1) g -> adj[v][w] = 1;

    if(d == 2){
        g -> adj[v][w] = 1;
        g -> adj[w][v] = 1;
    }
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


void GRAPHtc(Graph *G) {
	int i, s, t;
	G->tc = MATRIXInit(G->v, G->v, 0);
	
	// Faz uma copia de todas as conexões diretas
	for (s = 0; s < G->v; s++) {
		for (t = 0; t < G->v; t++) {
			G->tc[s][t] = G->adj[s][t];
		}
	}
	
	// Marca todos os vertices que se conectam a si mesmos
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
}
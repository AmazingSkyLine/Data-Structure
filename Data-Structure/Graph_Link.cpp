# include<bits/stdc++.h>
using namespace std;

# define MAX_SIZE 999

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
	int data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_SIZE];

typedef struct {
	int vexnum, arcnum;
	AdjList vertices;
}Graph;

void InitGraph(Graph &G){
	int vexnum, arcnum;
	cin >> vexnum >> arcnum;
	G.vexnum = vexnum;
	G.arcnum = arcnum;

	for(int i=1; i<=G.vexnum; i++)
		G.vertices[i].firstarc = NULL;
}

void CreateGraph(Graph &G){
	InitGraph(G);

	int in, out;
	for(int i=1; i<=G.arcnum; i++){
		cin >> in >> out;
		ArcNode *p = new ArcNode;
		G.vertices[in].data = in;
		G.vertices[out].data = out;
		p->adjvex = out;
		p->nextarc = G.vertices[in].firstarc;
		G.vertices[in].firstarc = p;
	}
}

void InitVisited(Graph &G, int *visited){
	for(int i=1; i<=G.vexnum; i++)
		visited[i] = 0;
}

void DFS(Graph &G, int *visited, int v){
	visited[v] = 1;
	cout << v << " ";

	int j;
	for(ArcNode *w=G.vertices[v].firstarc; w; w=w->nextarc){
		j = w->adjvex;
		if(!visited[j])
			DFS(G, visited, j);
	}
}

void DFSearch(Graph &G, int* visited){
	InitVisited(G, visited);

	for(int i=1; i<=G.vexnum; i++){
		if(!visited[i])
			DFS(G, visited, i);
	}
}

void BFS(Graph &G, int *visited){
	InitVisited(G, visited);

	queue<int> Q;
	int i, j;

	for(i=1; i<=G.vexnum; i++){
		if(!visited[i]){
			visited[i] = 1;
			cout << i << " ";
			Q.push(i);

			while(!Q.empty()){
				int tmp = Q.front();
				Q.pop();

				for(ArcNode *w=G.vertices[tmp].firstarc; w; w=w->nextarc){
					j = w->adjvex;
					if(!visited[j]){
						visited[j] = 1;
						cout << j << " ";
						Q.push(j);
					}
				}
			}
		}
	}
}

int main(){
	Graph G;
	CreateGraph(G);

	int visited[G.vexnum + 1];

	DFSearch(G, visited);
	cout << endl;
	BFS(G, visited);
	cout << endl;
}

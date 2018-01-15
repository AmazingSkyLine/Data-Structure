# include<bits/stdc++.h>
using namespace std;

# define MAX 100

int mat[MAX][MAX];

void DFS(int *visited, int v, int vexnum){
	visited[v] = 1;
	cout << v << " ";
	for(int i=1; i<=vexnum; i++){
		if(mat[v][i] == 1 && !visited[i])
			DFS(visited, i, vexnum);
	}
}

void DFSearch(int *visited, int vexnum){
	for(int i=1; i<=vexnum; i++){
		if(!visited[i])
			DFS(visited, i, vexnum);
	}
}

int main(){
	int vexnum, arcnum;
	cin >> vexnum >> arcnum;
	
	int i, j, in, out;
	
	int visited[vexnum+1];
	
	for(i=1; i<=vexnum; i++)
		visited[i] = 0;
	
	for(i=1; i<=vexnum; i++)
		for(j=1; j<=vexnum; j++)
			mat[i][j] = 0;
			
	for(i=1; i<=arcnum; i++){
		cin >> in >> out;
		mat[in][out] = 1;
		mat[out][in] = 1;
	}
	
	DFSearch(visited, vexnum);
}

// bt.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue> 

using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))


void printGraphBFSConn(vector<int> adj[], int v,int s)
{
	//Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
	int i = 0,j=0;
	//this is the difference in graph & tree prints, here we have visited array to avoid duplicate printing & in tree this issue never happends
	bool *visited=new bool[v];
	for (i = 0; i < v; i++) {
		visited[i] = false;
	}
	queue <int> q;
	q.push(s);
	visited[s]=true;
	while ( q.empty()==false ) {
		int u = q.front();
		cout << u << ", ";
		q.pop();
		for (int v:adj[u]) {
			if (visited[v]==false) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	delete visited;
	return;
}

void printGraphBFS(vector<int> adj[], int l, int s,bool visited[])
{
	//Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
	int i = 0, j = 0;
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while (q.empty() == false) {
		int u = q.front();
		cout << u << ", ";
		q.pop();
		for (int v : adj[u]) {
			if (visited[v] == false) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return;
}

void printGraphBFSDisconn(vector<int> adj[], int l)
{
	/*
	* time O(v+e)
	
	*/
	//Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
	int i = 0, j = 0;
	//this is the difference in graph & tree prints, here we have visited array to avoid duplicate printing & in tree this issue never happends
	bool* visited = new bool[l];
	for (i = 0; i < l; i++) {
		visited[i] = false;
	}
	for (i = 0; i < l; i++) {
		if (visited[i] == false) {
			printGraphBFS(adj, l, i, visited);
		}
	}
	delete visited;
	return;
}

void printGraphDFSRecur(vector<int> adj[], bool* visited, int s)
{
	if (visited[s] == false) {
		cout << s << ", ";
		visited[s] = true;
		for (auto v : adj[s]) {
			printGraphDFSRecur(adj, visited, v);
		}
	}
	return;
}
void printGraphDFSConn(vector<int> adj[], int l,int s)
{
	/*
	* O(v+e)

	*/
	bool* visited = new bool[l];
	for (int i = 0; i < l; i++) {
		visited[i] = false;
	}
	printGraphDFSRecur(adj, visited, 0);
	delete visited;

	return;
}
void printGraphDFSDisconn(vector<int> adj[], int l, int s)
{
	/*
	*O(v+e)
	*/
	bool* visited = new bool[l];
	for (int i = 0; i < l; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < l; i++) {
		if (visited[i] == false) {
			printGraphDFSRecur(adj, visited, i);
		}
	}
	delete visited;

	return;
}

void shortestPathUnweighted(vector <int> adj[],int l,int s) {
	/*
	* use BFS for shortest path
	* 
	*/
	int* dist = new int[l];
	bool* visited = new bool[l];
	for (int i = 0; i < l; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	dist[s] = 0;
	while (q.empty() == false) {
		int v = q.front();
		q.pop();
		for (auto u : adj[v]) {
			if (visited[u] == false) {
				visited[u] = true;
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	for (int i = 0; i < l; i++) {
		cout << dist[i] << ",";
	}
	delete dist;
	delete visited;

}

bool cycleDectectUndirectedBFS(vector<int> adj[],int l,int s) {
	int i;
	queue<int> q;
	bool *visited = new bool[l];
	bool loopDetected = false;

	for (i = 0; i < l; i++) {
		visited[i] = false;
	}
	q.push(s);
	visited[0] = false;
	while (loopDetected ==false && q.empty() == false) {
		int u=q.front();
		q.pop();
		for (auto v : adj[u]) {
			//test for visited as well parent in the case of undirected!!!
			if (visited[v] == false && v!=u) {
				visited[v] = true;
			}
			else {
				loopDetected=true;
			}
		}
	}
	delete visited;
	return loopDetected;
}

bool cycleDetectUndirectedDFSRecur(vector<int> adj[], int s,int p,bool *visited) {
	bool cycleDetected = false;
	visited[s] = true;
	for (auto v : adj[s]) {
		if (visited[v] == false) {
			cycleDetected=cycleDetectUndirectedDFSRecur(adj, v,p, visited);
		}
		else if(s!=v) {
			//is not a parent loop detected
			cycleDetected = true;
			break;
		}
	}
	return cycleDetected;
}

bool cycleDectectUndirectedDFS(vector<int> adj[], int l) {
	
	/*
	* time O(v+e)
	*/
	int i;
	bool loopDetected;
	bool *visited=new bool[l];
	for (i = 0; i < l; i++) {
		visited[i] = false;
	}
	for (i = 0; i < l; i++) {
		if (visited[i] == false) {
			//parent first call is -1!!!!!?????
			//investigage if it is required for 
			loopDetected=cycleDetectUndirectedDFSRecur(adj, i,-1,visited);
		}
	}
	delete visited;
	return loopDetected;
}

void shortestPathDAG(vector<int> adj[], vector<int> weights[],int l) {
	/*
	* directed acylic graph
	
	*/

}

//int primAlgo(vector<int> graph[], vector<int> mst[], int cols, int rows) {
//	int r,c;
//	for (c = 0; c < cols; c++) {
//		for (r = 0; r < rows; r++) {
//
//			for (c = 0; c < cols; c++) {
//				for (r = 0; r < rows; r++) {
//					if (graph[r][c])
//				}
//			}
//		}
//}

void addEdge(vector<int> adj[], int v, int u) {
	//undirected graph
	adj[v].push_back(u);
	adj[u].push_back(v);
	return;
}
void graph() {
	vector<int> adj[5];
	addEdge(adj,0,1);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 0);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	//addEdge(adj, 3, 1);
	addEdge(adj, 4, 2);
	addEdge(adj, 3, 4);

//	cout<<"cycleDectectUndirectedBFS="<<cycleDectectUndirectedBFS(adj, 5, 0)<<endl; 
	cout << "cycleDectectUndirectedDFS=" << cycleDectectUndirectedDFS(adj, 5); return;

	shortestPathUnweighted(adj, 5,0); return;
	
	printGraphDFSDisconn(adj, 5, 0);
	printGraphDFSConn(adj, 5, 0);

	printGraphBFSDisconn(adj, 5);
	printGraphBFSConn(adj,5,0);
	return;
}

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int dfsRecur(vector<int>adj[],int s,bool *visited,int *visitCnt){
        visited[s]=true;
        int childCnt=0;
        for(auto v:adj[s]){
            if(visited[v]==false){
                int ret=dfsRecur(adj,v,visited,visitCnt);
                childCnt+=ret+1;
            }
        }
        visitCnt[s]=childCnt;
        return childCnt;
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int ret=-1;
	    bool visited[V];
	    int visitCnt[V];
	    
	    bzero(visitCnt,sizeof(visitCnt));
	    for(int i=0;i<V;i++){
	       bzero(visited,sizeof(visited));
	       if((V-1)==dfsRecur(adj,i,visited,visitCnt)){
	           ret=i;
	           break;
	       }
	    }
	    return ret;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
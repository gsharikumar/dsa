//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int level=-1;
	    int currLevel[V];
        int visited[V];
        queue <int> q;
        
        bzero(visited,sizeof(visited));
        bzero(currLevel,sizeof(currLevel));
        q.push(0);
        while(q.empty()==false){
            int s=q.front();
            visited[s]=1;
            q.pop();
            if(s==X){
                level=currLevel[s];
                break;
            }
            
            for(auto v:adj[s] ){
                if(visited[v]==0){
                    currLevel[v]=currLevel[s]+1;
                    q.push(v);
                    visited[v]=1;
                }
            }
            
            
        }
        return level;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
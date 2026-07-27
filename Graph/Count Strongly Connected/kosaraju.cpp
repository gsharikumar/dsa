

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void topoDFS(vector<int> adj[],int n,bool visited[],stack<int> &s)
    {
        if(visited[n] == true)
        {
            return;
        }
        visited[n] = true;
        for(auto v:adj[n]){
            topoDFS(adj,v,visited,s);
            
        }
        s.push(n);
       // cout<<n<<endl;


        return;
    }
    
    void dfsTouch(vector<int> adj[],int n,bool visited[])
    {
        if(visited[n] == true)
        {
            return;
        }
        visited[n] = true;
        for(auto v:adj[n]){
             dfsTouch(adj,v,visited);
        }
        return;
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int i;
        stack<int> s;
        bool visited[V]={false};
        bzero(visited,sizeof(visited));
#if 0
        for(i = 0;i < V;i++){
            cout << i <<"->";
            for(auto v:adj[i]){
                cout << v <<" ";                            
            }
            cout<<endl;
        }
        cout <<"-----------"<<endl;
#endif
        for(i = 0;i < V;i++){
            topoDFS(adj,i,visited,s);
        }
        vector<int> tadj[V];
        for(i = 0;i < V;i++){
            for(auto v:adj[i]){
                tadj[v].push_back(i);
            }
        }
#if 0
        for(i = 0;i < V;i++){
            cout << i <<"->";
            for(auto v:tadj[i]){
                cout << v <<" ";                            
            }
            cout<<endl;
        }
        cout <<"-----------"<<endl;
#endif        
        bzero(visited,sizeof(visited));
        int ccCount = 0;
        while(!s.empty())
        {
            int n = s.top();
            //cout<<n<<" ";
            if(visited[n] == false){
                dfsTouch(tadj,n,visited);
                ccCount++;
            }
            s.pop();
        }
        
        return ccCount;
    }
};
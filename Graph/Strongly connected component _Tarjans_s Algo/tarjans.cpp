//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfsTarjan(vector<int> adj[], int node,int parent,int &timer,bool visited[],int disc[],int low[],bool inStk[],stack<int> &stk,vector<vector<int>> &scc)
    {
        visited[node] = true;
        disc[node]=low[node]= timer++;
        stk.push(node);
        inStk[node] = true;
        for(auto c:adj[node]){
            //if(parent == c){
            //    continue;
            //}
            if(visited[c] == false){
                dfsTarjan(adj,c,node,timer,visited,disc,low,inStk,stk,scc);
                low[node] = min(low[node],low[c]);
            }else{
                if(inStk[c] == true){
                    low[node] = min(low[node],low[c]);
                }
            }
        }

        if(low[node] == disc[node]){
            vector<int> cc;
            while(!stk.empty()){
                int v = stk.top();
                stk.pop();
                inStk[v] = false;
                cc.push_back(v);
                //cout << v <<",";
                if(v == node){
                    break;
                }
            }
            //cout<<endl;
            sort(cc.begin(), cc.end());
            scc.push_back(cc);
        }
        
    }
    
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        int i;
        vector<vector<int>> scc;        
        stack<int> stk;
        bool visited[V] = {false};
        bool inStk[V] = {false};
        int disc[V] = {INT_MAX};
        int low[V] = {INT_MAX};
        int timer = 0;

        for(i = 0;i < V;i++){
            if(visited[i] == false){
                dfsTarjan(adj,i,-1,timer,visited,disc,low,inStk,stk,scc);
            }
        }
        sort(scc.begin(), scc.end());
        return scc;
    }
};
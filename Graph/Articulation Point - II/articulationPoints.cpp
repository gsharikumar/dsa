class Solution {
  public:
   void dfs(vector<int>adj[],int node,int parent,int &timer,bool visited[],int disc[],int low[],bool isAP[])
    {
        visited[node] = true;
        low[node] = disc[node] = timer++;
        int children = 0;
        for(auto v:adj[node]){
            if(parent == v){
                continue;
            }
            if(visited[v] == false){
                children++;
                dfs(adj,v,node,timer,visited,disc,low,isAP);
                low[node] = min(low[v],low[node]); 
                if(low[v] >= disc[node] && parent != -1){
                    isAP[node] = true;
                }
            }else{
                low[node] = min(disc[v],low[node]); //low[node] = min(low[v],low[node]); will not work!!!
            }
        }
        if(children > 1 && parent == -1){
            isAP[node] = true;   
        }

    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int disc[V] = {INT_MAX};
        int low[V] = {INT_MAX};
        bool visited[V] = {false};
        bool isAP[V]={false}; //!! it is possible a entry is added to AP list twice, using array eliminates the corner case
        vector<int> ap;
        int i;
        int timer = 0;
        
        //cout <<"---------"<<endl;
        for(i = 0;i < V;i++){
            if(visited[i] == false){
                dfs(adj,i,-1,timer,visited,disc,low,isAP);
            }
        }
        for(i = 0;i < V;i++){
            if(isAP[i] == true){
                ap.push_back(i);
            }
        }
        if(ap.empty()){
         ap.push_back(-1);   
        }
        return ap;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int i;
        int j;
        int mstSum = 0;
        
        bool mstSet[V] = {false};
        int key[V] = {INT_MAX};
        for(i = 0;i < V;i++){
            key[i] = INT_MAX;
            mstSet[i] = false;
        }
        key[0] = 0;
        
        for(i = 0;i < V;i++){

            //find index of the smallest key and at the same time not in a mst set 
            int minIdx = -1;
            for(j = 0;j < V;j++){
                if(mstSet[j] == false && (minIdx == -1 || key[j] < key[minIdx]))
                {
                    minIdx = j;
                }
            }
 
            mstSet[minIdx] = true;
            mstSum += key[minIdx];
            
            //cout<<"workNode="<<minIdx <<" minKey="<<key[minIdx]<<endl;
            //update the key values for the nodes connected to the newly found/added mst node above
            for(auto l:adj[minIdx]){
                //cout<<minIdx<<"->"<<l[0]<<","<<l[1]<<endl;
                if(mstSet[l[0]] == false && key[l[0]] > l[1]){
                    key[l[0]] = l[1];
                    //cout<<"updating"<<key[l[0]]<<endl;
                }
            }
            //cout<<endl;
            //cout<<"workNode="<<minIdx<<endl ;//<<" minNode="<<minNode<<" minWei="<<minWeight<<endl;
        }
        return mstSum;
    }
};
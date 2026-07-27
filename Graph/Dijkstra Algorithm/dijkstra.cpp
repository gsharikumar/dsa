class Solution
{
    struct hNode{
        int node;
        int weight;
        bool visited;
    };
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int getMinDistIdx(struct hNode hArr[],int len)
    {
        int minDist = INT_MAX;
        int minIdx = 0;
        int i = 0;
        while(i<len){
            if(hArr[i].visited ==false && hArr[i].weight < minDist){
                minDist = hArr[i].weight;
                minIdx = i;
            }
            i++;
        }
        return minIdx;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        int i;
        vector <int> vec;
        struct hNode hArr[V];
        for(i = 0;i < V;i++){
            hArr[i].node = i;
            hArr[i].weight = INT_MAX;
            hArr[i].visited = false;
        }

        hArr[S].weight = 0;
        hArr[S].node = S;
        
        //cout <<"S="<<S<<"hArr[S].weight="<<hArr[S].weight<<endl;
        i = 0;
        while(i < V){
            int minIdx = getMinDistIdx(hArr,V);
            
            int sW = hArr[minIdx].weight;
            int sI = hArr[minIdx].node;
            //cout <<"next node="<<sI<<" weigth="<<sW<<endl;
            for(auto v:adj[sI]){
                int tI = v[0];
                int tW = v[1];
                //cout <<"working on adj node="<<tI<<" with weigth="<<tW <<"visited[tI]="<<visited[tI]<<endl;
                if(hArr[tI].visited == false){
                    int nW = sW + tW;
                    //cout <<"nW="<<nW<<"weight[tI]="<<weight[tI]<<endl;
                    if(hArr[tI].weight > nW){
                        //cout <<"node="<< tI <<" upd wt="<<weight[tI] <<"-->" << nW <<endl;
                        //insert the update
                        hArr[tI].weight = nW;
                    }
                }
            }
            //cout <<"pushing weight="<<sW<<" to index="<< sI<<endl;
            hArr[sI].visited =  true;  
            i++;
        }
        for(i=0;i < V;i++){
            vec.push_back(hArr[i].weight);
        }
        return vec;
    };


    
    int left(int i)
    {
        return (i*2+1);    
    }

    int right(int i)
    {
        return (i*2+2);    
    }
    
    int parent(int i)
    {
        return floor((i-1)/2.0);
    }
    
    void heapifyMin(struct hNode arr[],int n,int i)
    {
        if(i <= 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int minIdx = idx;
        if(l>=0 && l<n && arr[l].weight < arr[minIdx].weight)
        {
            minIdx = l;
        }
        if(r>=0 && r<n && arr[r].weight < arr[minIdx].weight)
        {
            minIdx = r;
        }
        if(minIdx != idx)
        {
            swap(arr[minIdx],arr[idx]);
            heapifyMin(arr,n,idx);
        }
        return;
    }
    
    struct hNode extractMin(struct hNode arr[],int n)
    {
        if(n <= 0)
        {
            struct hNode endNode = {-1,-1,-1};
            return endNode;
        }

        struct hNode root = arr[0];
        arr[0] = arr[n-1];
        int i = 0;
        while(1)
        {
            int l = left(i);
            int r = right(i);
            int minIdx = i;
            if(l < n && arr[l].weight < arr[minIdx].weight )
            {
                minIdx = l;
            }
            if(r < n && arr[r].weight < arr[minIdx].weight )
            {
                minIdx = r;
            }
            if(minIdx != i)
            {
                swap(arr[minIdx],arr[i]);
                i = minIdx;
            }else
            {
                break;
            }
        }
        return root;
        
    }

    
    vector <int> dijkstraminHeap(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        int i;
        vector <int> vec;
        struct hNode hArr[V];
        bool visited[V]={false};
        int weight[V]={INT_MAX};
        for(i = 0;i < V;i++){
            hArr[i].node = i;
            hArr[i].weight = INT_MAX;
            hArr[i].visited = false;
            visited[i] = false;
            weight[i] = INT_MAX;
        }

        weight[S] = 0;
        hArr[S].weight = 0;
        hArr[S].node = S;
        heapifyMin(hArr,V,S);
        //cout <<"S="<<S<<"hArr[S].weight="<<hArr[S].weight<<endl;
        int vCnt = V;
        while(vCnt){
            struct hNode hn = extractMin(hArr,vCnt);
            vCnt--;
            
            int sW = hn.weight;
            int sI = hn.node;
            //cout <<"next node="<<sI<<" weigth="<<sW<<endl;
            for(auto v:adj[sI]){
                int nW;
                int tI = v[0];
                int tW = v[1];
                //cout <<"working on adj node="<<tI<<" with weigth="<<tW <<"visited[tI]="<<visited[tI]<<endl;
                if(visited[tI] == false){
                    nW = sW + tW;
                    //cout <<"nW="<<nW<<"weight[tI]="<<weight[tI]<<endl;
                    if(weight[tI] > nW){
                        //cout <<"node="<< tI <<" upd wt="<<weight[tI] <<"-->" << nW <<endl;
                        weight[tI] = nW;
                        
                        //insert the update
                        hArr[tI-(V-vCnt)].weight = nW;
                        hArr[tI-(V-vCnt)].node = tI;
                        heapifyMin(hArr,vCnt,tI-(V-vCnt));
                    }
                }
            }
            //cout <<"pushing weight="<<sW<<" to index="<< sI<<endl;
            visited[sI] =  true;   
        }
        for(int i=0;i<V;i++){
            vec.push_back(weight[i]);
        }
        return vec;
    }
};
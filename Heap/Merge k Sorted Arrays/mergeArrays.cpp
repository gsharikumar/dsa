//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct hNode{
        int data;
        int arrayid;
        int idx;
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
    
    void heapify(struct hNode arr[],int n,int i)
    {
        if(i < 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int minIdx = idx;
        if(l>=0 && l<n && arr[l].data < arr[minIdx].data)
        {
            minIdx = l;
        }
        if(r>=0 && r<n && arr[r].data < arr[minIdx].data)
        {
            minIdx = r;
        }
        if(minIdx != idx)
        {
            swap(arr[minIdx],arr[idx]);
            heapify(arr,n,idx);
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
            if(l < n && arr[l].data < arr[minIdx].data )
            {
                minIdx = l;
            }
            if(r < n && arr[r].data < arr[minIdx].data )
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

    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        int len[K]; 
        struct hNode harr[K];
        int i;
        for(i = 0;i < K;i++)
        {
            harr[i].data = arr[i][0];
            harr[i].arrayid = i;
            harr[i].idx = 0;
            heapify(harr,i+1,i);
            len[i] = arr[i].size();
        }
        vector<int> vec;
        int hSize = K;        
        while(hSize > 0)
        {
            struct hNode n = extractMin(harr,hSize);
            vec.push_back(n.data);
            n.idx += 1;
            if(n.idx == len[n.arrayid])
            {
                //array node expired, pick the next
                hSize--;
            }else{
                n.data = arr[n.arrayid][n.idx];
                harr[hSize-1] = n;
                heapify(harr,hSize,hSize-1);
            }
        }
        return vec;
        
    }
};
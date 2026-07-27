class Solution
{
    private:
        vector <int> leftMaxHeap;
        vector <int> rightMinHeap;
    public:
    //Function to insert heap.
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
    
    
    void heapifyMin(vector <int> &arr,int n,int i)
    {
        if(i <= 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int minIdx = idx;
        if(l>=0 && l<n && arr[l] < arr[minIdx])
        {
            minIdx = l;
        }
        if(r>=0 && r<n && arr[r] < arr[minIdx])
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
    
    void heapifyMax(vector <int> &arr,int n,int i)
    {
        if(i <= 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int maxIdx = idx;
        if(l>=0 && l<n && arr[l] > arr[maxIdx])
        {
            maxIdx = l;
        }
        if(r>=0 && r<n && arr[r] > arr[maxIdx])
        {
            maxIdx = r;
        }
        if(maxIdx != idx)
        {
            swap(arr[maxIdx],arr[idx]);
            heapifyMax(arr,n,idx);
        }
        return;
    }
    

    
    int extractMin(vector <int> &arr,int n)
    {
        if(n <= 0)
        {
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[n-1];
        int i = 0;
        while(1)
        {
            int l = left(i);
            int r = right(i);
            int minIdx = i;
            if(l < n && arr[l] < arr[minIdx] )
            {
                minIdx = l;
            }
            if(r < n && arr[r] < arr[minIdx] )
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
    
    int extractMax(vector <int> &arr,int n)
    {
        if(n <= 0)
        {
            return -1;
        }

        int root = arr[0];
        arr[0] = arr[n-1];
        int i = 0;
        while(1)
        {
            int l = left(i);
            int r = right(i);
            int maxIdx = i;
            if(l < n && arr[l] > arr[maxIdx] )
            {
                maxIdx = l;
            }
            if(r < n && arr[r] > arr[maxIdx] )
            {
                maxIdx = r;
            }
            if(maxIdx != i)
            {
                swap(arr[maxIdx],arr[i]);
                i = maxIdx;
            }else
            {
                break;
            }
        }
        return root;
        
    }
    
    void insertHeap(int &x)
    {
        leftMaxHeap.push_back(x);
        int lSize = leftMaxHeap.size();
        heapifyMax(leftMaxHeap,lSize,lSize-1);
        balanceHeaps();
        return;
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int lSize;
        int rSize;
        #if 0
        cout << "bef left=";
        for (auto i: leftMaxHeap)
            std::cout << i << ' ';
        cout << "right=";
        for (auto j: rightMinHeap)
            std::cout << j << ' ';
        cout<<"--"<<endl;
        #endif
        lSize = leftMaxHeap.size();
        rSize = rightMinHeap.size();

        if((lSize > 0 && rSize > 0) && (leftMaxHeap[0] > rightMinHeap[0]))
        {
            int val = extractMax(leftMaxHeap,lSize);
            leftMaxHeap.pop_back();
            lSize = leftMaxHeap.size();
            
            rightMinHeap.push_back(val);
            rSize = rightMinHeap.size();
            heapifyMin(rightMinHeap,rSize,rSize-1);    
        }

        #if 1
        lSize = leftMaxHeap.size();
        rSize = rightMinHeap.size();
        //cout <<"lSize="<<lSize<<" rSize="<<rSize<<endl;

       // while(abs(lSize-rSize)>1)
        {
            if(lSize> (rSize + 1)){
                int val = extractMax(leftMaxHeap,lSize);
                leftMaxHeap.pop_back();
                lSize = leftMaxHeap.size();
                
                rightMinHeap.push_back(val);
                rSize = rightMinHeap.size();
                heapifyMin(rightMinHeap,rSize,rSize-1);
            }
            if(rSize> (lSize + 1)){
                int val = extractMin(rightMinHeap,rSize);
                rightMinHeap.pop_back();
                rSize = rightMinHeap.size();
                
                leftMaxHeap.push_back(val);
                lSize = leftMaxHeap.size();
                heapifyMax(leftMaxHeap,lSize,lSize-1);
            }
        }
        #endif
        #if 0
        cout << "aft left=";
        for (auto i: leftMaxHeap)
            std::cout << i << ' ';
        cout << "right=";
        for (auto j: rightMinHeap)
            std::cout << j << ' ';
        cout<<"--"<<endl;
        #endif
        return;
    }
    
    //Function to return Median.
    double getMedian()
    {
        int lSize = leftMaxHeap.size();
        int rSize = rightMinHeap.size();
        if(lSize > rSize)
        {
            return (double)leftMaxHeap[0];
        }
        else if(rSize > lSize)
        {
            return (double)rightMinHeap[0];
        }
        else
        {
            return (leftMaxHeap[0] + rightMinHeap[0])/2.0;

        }
        
    }
};
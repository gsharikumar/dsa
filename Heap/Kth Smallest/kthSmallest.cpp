

class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    int left(int i)
    {
        return 2*i+1;
    }
    
    int right(int i)
    {
        return 2*i+2;
    }
    
    int parent(int i)
    {
        return floor((i-1)/2.0);
    }
    
    void heapify(int arr[],int n,int i)
    {
        if(i <= 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int maxIdx = idx;
        
        if(l >= 0 && l < n && arr[l] > arr[maxIdx])
        {
            maxIdx = l;    
        }
        if(r >= 0 && r < n && arr[r] > arr[maxIdx])
        {
            maxIdx = r;
        }
        
        if(maxIdx != idx)
        {
            swap(arr[maxIdx],arr[idx]);
            heapify(arr,n,idx);
        }
        return;
    }
    
    int extractMax(int arr[],int n)
    {
        if(n < 0)
        {
            return -1;    
        }
        int root = arr[0];
        arr[0] = arr[n-1];
        int i =0;
        while(1)
        {
            int l = left(i);
            int r = right(i);
            int maxIdx = i;
            if(l < n && arr[l] > arr[maxIdx])
            {
                maxIdx = l;
            }
            if(r < n && arr[r] > arr[maxIdx])
            {
                maxIdx = r;
            }
            if(maxIdx != i)
            {
                swap(arr[maxIdx],arr[i]);
                i = maxIdx;
            }else{
                break;
            }
        }
        return root;
        
        
    }
    
    int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        int i;
        for(i=0;i < k;i++)
        {
            heapify(arr,i+1,i);
        }
        
        for(;i < n;i++)
        {
            if(arr[0] > arr[i])
            {
                extractMax(arr,k);
                arr[k-1] = arr[i];
                heapify(arr,k,k-1);
            }
        }
        
        return arr[0];
        
    }
};
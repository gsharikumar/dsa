

class Solution
{
    public:
    //Function to return kth largest element from an array.
    
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
    
    void heapify(int arr[],int n,int i)
    {
        if(i < 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int minIdx = idx;
        if(l>=0 && l<n && arr[l] < arr[idx])
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
            heapify(arr,n,idx);
        }
        return;
    }

    
    int extractMin(int arr[],int n)
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
            if(l < n && arr[l] < arr[i] )
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

    int KthLargest(int arr[], int n, int k) {
        // Your code here
        int i;
        for(i = 0;i < k;i++)
        {
            heapify(arr,i+1,i);
        }
        

        
        for(;i < n;i++)
        {
            if(arr[0] < arr[i])
            {
                extractMin(arr,k);
                arr[k-1] = arr[i];
                heapify(arr,k,k-1);
            }
        }
        for(i=0;i < k;i++)
        {
           // cout << extractMin(arr,k-i);    
        }
        return arr[0];
    }
};
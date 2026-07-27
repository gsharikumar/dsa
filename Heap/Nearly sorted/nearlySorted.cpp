class Solution
{
    public:
    //Function to return the sorted array.
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


    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        int i = 0;
        int j = 0;
        vector <int> vec;
        
        for(j = 0; j < k;j++)
        {
            heapify(&arr[0],j+1,j);
        }

        for(; j < n;j++)
        {
            heapify(&arr[j-k],k+1,k);
            //vec.push_back(extractMin(&arr[j-k],k+1));
        }
        for(j = 0; j < n;j++)
        {
            vec.push_back(extractMin(&arr[0],n-j));
            
        }

        i = 0;
        for(;j < n+k ;j++,i++)
        {
          //  vec.push_back(extractMin(&arr[j-k],k-i));
        }


        return vec;

    }
};
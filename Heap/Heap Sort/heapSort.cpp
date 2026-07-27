// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    int left(int i)
    {
        return (2*i+1);
    }

    int right(int i)
    {
        return (2*i+2);
    }
    
    int parent(int i)
    {
        return floor((i-1)/2.0);
    }

    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        // Your Code Here
        if(i <= 0)
        {
            return;
        }

        int idx = parent(i);
        int maxIdx = idx;
        int l = left(idx); 
        int r = right(idx);
        
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

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        int i = 0;
        while(i < n)
        {
            heapify(arr,i+1,i);
            i++;
        }
        //memcpy(arr,hArr,sizeof(int)*n);
        return;
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        if(n == 0)
        {
            return;
        }
        if(n == 1)
        {
            return;
        }

        buildHeap(arr,n);
        #if 1
        int len = n;
        while(len > 0)
        {
            swap(arr[0],arr[len-1]);
            len--;
            int i = 0;
            while(i < len)
            {
                int l = left(i);
                int r = right(i);
                int minIdx = i;
                if(l < len && arr[l] > arr[minIdx])
                {
                    minIdx = l;   
                }
                if(r < len && arr[r] > arr[minIdx])
                {
                    minIdx = r;   
                }
                if(minIdx != i)
                {
                    swap(arr[minIdx],arr[i]);
                    i = minIdx;
                }else{
                    break;
                }
            }
        }
        #endif
        return;
    }
};


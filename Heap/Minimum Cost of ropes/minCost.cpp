class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    
    long long left(long long i)
    {
        return 2*i+1;
    }

    long long right(long long i)
    {
        return 2*i+2;
    }
    
    long long parent(long long i)
    {
        return (i-1)/2.0;
    }


    
    void heapify(long long arr[],long n,long long i )
    {
        if(i <= 0)
        {
            return;
        }
        
        long long idx = parent(i);
        long long l = left(idx);
        long long r = right(idx);
        long long minIdx = idx;
        if(l>=0 && l < n && arr[l] < arr[minIdx] )
        {
            minIdx = l; 
        }
        if(r >= 0 && r < n && arr[r] < arr[minIdx] )
        {
            minIdx = r; 
        }
        
        if( minIdx != idx)
        {
            swap(arr[idx],arr[minIdx]);
            heapify(arr,n,idx);
        }
        return;
    }
    
    long long extractMin(long long arr[],long long n)
    {
        if(n <= 0){
            return -1;
        }
        long long root = arr[0];
        long long i = 0;
        arr[0] = arr[n-1];
        while(1)
        {
            long long l = left(i);
            long long r = right(i);
            long long minIdx = i;
            if(l >= 0 && l < n && arr[l] < arr[minIdx] )
            {
                minIdx = l; 
            }
            if(r >= 0 && r < n && arr[r] < arr[minIdx] )
            {
                minIdx = r; 
            }
            if(minIdx != i)
            {
                swap(arr[minIdx],arr[i]);
                i = minIdx;
            }
            else{
                break;
            }
        }
        return root;
    }
    
    
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long i = 0;
        for(i = 0;i < n;i++)
        {
            heapify(arr,i+1,i);
        }

        long long sum = 0;
        long long totalSum = 0;
        long long cnt = n;

        i = 0;
        while(cnt)
        {
            
            long long curr = extractMin(arr,cnt);
            cnt--;

            sum = sum + curr;

            if(!((i+1) % 2)){
                cnt++;
                arr[cnt-1] = sum;
                heapify(arr,cnt,cnt-1);
                totalSum += sum;
                sum = 0;
            }
            i++;
        }
        return totalSum;
    }
};
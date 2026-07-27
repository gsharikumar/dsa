class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
      struct hNode{
        char ch;
        int freq;
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
        if(i <= 0)
        {
            return;
        }
        int idx = parent(i);
        int l = left(idx);
        int r = right(idx);
        int maxIdx = idx;
        if(l>=0 && l<n && arr[l].freq > arr[maxIdx].freq)
        {
            maxIdx = l;
        }
        if(r>=0 && r<n && arr[r].freq > arr[maxIdx].freq)
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
    
    struct hNode extractMax(struct hNode arr[],int n)
    {
        if(n <= 0)
        {
            struct hNode endNode = {-1,-1};
            return endNode;
        }

        struct hNode root = arr[0];
        arr[0] = arr[n-1];
        int i = 0;
        while(1)
        {
            int l = left(i);
            int r = right(i);
            int maxIdx = i;
            if(l < n && arr[l].freq > arr[maxIdx].freq )
            {
                maxIdx = l;
            }
            if(r < n && arr[r].freq > arr[maxIdx].freq )
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


    string rearrangeString(string str)
    {
    	// Your code here
    	int i,j;
    	 string resultStr;
        int len = str.length();     
    	int freq[26]={0};
    	for(i = 0;i < len;i++){
    	    int s =(int)str[i]; 
            s = s - 'a';
            freq[s]++;	    
        }

        struct hNode harr[len];
        j = 0;
        for(i = 0;i < 26;i++){
            if(freq[i] != 0)
            {
                harr[j].ch = i;
                harr[j].freq = freq[i];
                heapify(harr,j+1,j);
                j++;
            }
        }

        int k = j;
        while(k > 0){
            struct hNode n1 = extractMax(harr,k); 
            if(n1.freq > 0)
            {
                k--;
                n1.freq--;
                resultStr += (n1.ch + 'a');
            }
            struct hNode n2 = extractMax(harr,k); 
            if(n2.freq > 0)
            {
                k--;
                n2.freq--;
                resultStr += (n2.ch + 'a');
            }

            if(n1.freq > 0){
                k++;
                harr[k-1] = n1;
                heapify(harr,k,k-1);
            }
            if(n2.freq > 0){
                k++;
                harr[k-1] = n2;
                heapify(harr,k,k-1);
            }

        }
        //cout <<resultStr<< "------"<<endl;
        return resultStr;
    }
};
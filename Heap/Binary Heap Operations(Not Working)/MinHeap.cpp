

/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/



//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    // Your code here
    int root = -1;
    if(heap_size == 0){
        return root;   
    }
    if(heap_size == 1){
        root = harr[0];
        heap_size--;
        return root;   
        
    }

    root = harr[0];
    swap(harr[0],harr[heap_size-1]);
    harr[heap_size-1] = 0;
    
    heap_size--;
    //heapify
    if(heap_size > 0)
    {
        MinHeapify(0);
    }
    return root;
    
#if 0
    int idx = 0;
    while(1){
        int l = left(idx);
        int r = right(idx);
        int smallestIdx = idx; 
        
        if(l < heap_size && harr[l] < harr[smallestIdx])
        {
            smallestIdx = l;
        }
        if(r < heap_size && harr[r] < harr[smallestIdx])
        {
            smallestIdx = r;
        }
        if(smallestIdx != idx)
        {
            swap(harr[smallestIdx],harr[idx]);
            idx = smallestIdx;
        }else{
            break;
        }
    }
#endif
}


//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    if(i < heap_size){
        decreaseKey(i,INT_MIN);
        
        int drop = extractMin();
    }
    return;
    
    
#if 0
    harr[i] = INT_MIN;
    while(1)
    {
        int p = parent(i);
        if(p>=0){
            swap(harr[p],harr[i]);
            i = p;
        }else{
            break;
        }
    }
    int valDrop = extractMin();
    return;
#endif

}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    // Your code here
    if(heap_size < capacity)
    {
        decreaseKey(heap_size,k);
        heap_size++;
    }
    return;

#if 0
    harr[heap_size] = k;

    int idx = parent(heap_size);
    
    //heapify
    
    while(1)
    {
        int l = left(idx);
        int r = right(idx);
        int smallestIdx = idx;
        if(l >=0 && harr[l] < harr[smallestIdx])
        {
            smallestIdx = l;
        }
        if(r >=0 && harr[r] < harr[smallestIdx])
        {
            smallestIdx = r;
        }
        if(smallestIdx != idx)
        {
            swap(harr[smallestIdx],harr[idx]);
            idx = parent(smallestIdx);
        }else{
            break;
        }
    }
    heap_size++;
#endif
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
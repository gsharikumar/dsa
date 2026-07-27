

//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* createNode(int d)
{
    Node *n = (Node*)calloc(1,sizeof(Node*));
    n->data = d;
    return n;
}

Node* constructBst(int arr[], int n)
{
    // Code here
    
    queue<pair<Node *,pair<int,int>>> q;
    Node *root = createNode(arr[0]);
    q.push({root,{INT_MIN,INT_MAX}});
    
    int i = 1;
    while( i < n){
        Node *nn = q.front().first;
        int min = q.front().second.first;
        int max = q.front().second.second;
        q.pop();
        
        if(arr[i] > min && arr[i] < nn->data){
            nn->left = createNode(arr[i]);
            q.push({nn->left,{min,nn->data}});
            i++;
            
        }
        if(arr[i] > nn->data && arr[i] < max && i < n){
            nn->right = createNode(arr[i]);
            q.push({nn->right,{nn->data,max}});
            i++;
        }
    }
    return root;
    
}


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* createNode(int data)
{
    Node* node=(Node*)calloc(1,sizeof(Node));
    node->data=data;
    return node;
}

Node* buildTreeRecur(int in[],int post[],int n)
{
    Node *root;
    if(n<=0){
        return NULL;
    }    
    
    int rootIdx=0;

    while(in[rootIdx] != post[n-1]){
        rootIdx++;
    }
    root=createNode(in[rootIdx]);
    
    root->left=buildTreeRecur(&in[0],&post[0],rootIdx);
    root->right=buildTreeRecur(&in[rootIdx+1],&post[rootIdx],n-rootIdx-1);
    return root;
    
} 


Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return buildTreeRecur(in,post,n);
    
}


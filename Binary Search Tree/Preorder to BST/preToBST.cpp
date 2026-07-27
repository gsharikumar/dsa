//User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* constructBST(int pre[],int size,int &idx,int min,int max)
    {
        
        if(idx >= size)
        {
            return NULL;
        }
        if(!(pre[idx]>min && pre[idx]<max))
        {
            return NULL;
        }
        Node *root = newNode(pre[idx]);
        
        idx++;
        root->left = constructBST(pre,size,idx,min,root->data);
        root->right = constructBST(pre,size,idx,root->data,max);
        return root;
    }
    
    Node* post_order(int pre[], int size)
    {
        //code here
        int idx = 0;
        return  constructBST(pre,size,idx,INT_MIN,INT_MAX);
    }
};
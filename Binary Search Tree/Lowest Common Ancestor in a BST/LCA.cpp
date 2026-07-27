



//Function to find the lowest common ancestor in a BST. 

Node* LCARecur(Node *root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left;
    Node *right;
    
    left = LCARecur(root->left,n1,n2);
    right = LCARecur(root->right,n1,n2);

    if(left == NULL)
    {
        return right;
    }
    else if(right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
    return LCARecur(root,n1,n2);
}

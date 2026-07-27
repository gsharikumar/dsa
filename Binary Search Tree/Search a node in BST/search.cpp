

// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root == NULL)
    {
        return false;
    }
    if(root->data > x)
    {
        return search(root->left,x);
    }
    else if(root->data < x)
    {
        return search(root->right,x);
    }else{
        return true;
    }
    
}


// Function to insert a node in a BST.
Node* createNode(int key)
{
    
    Node* node = (Node*)calloc(1,sizeof(Node*));
    node->data = key;
    return node;
}

Node* insertBst(Node* root,int key)
{
    if(root == NULL)
    {
        //insert the new node
        
        return createNode(key);
    }
    
    if(root->data > key)
    {
        root->left = insertBst(root->left,key);
            
    }
    else if(root->data < key)
    {
        root->right = insertBst(root->right,key);
    }
    //key already present no updates, return as such
    return root;
}

Node* insert(Node* root, int Key) {
    // Your code here
    
    return insertBst(root, Key);

}
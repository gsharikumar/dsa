// User function Template for C++

// Function to return the level order traversal of a BST.
vector<int> levelOrder(struct Node* node) {
    // code here
    vector<int> loList;
    if(node == NULL)
    {
        return loList;
    }
    queue<Node*> q;
    
    q.push(node);
    
    while( !q.empty() )
    {
        Node *n = q.front();
        q.pop();
        
        loList.push_back(n->data);

        if(n->left)
        {
            q.push(n->left);            
        }
        if(n->right)
        {
            q.push(n->right);
        }
    }
    return loList;
}
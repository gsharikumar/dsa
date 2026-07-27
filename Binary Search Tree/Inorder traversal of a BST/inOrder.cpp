// User function Template for C++

// Function to return a list containing the inorder traversal of the BST.

void inOrderRecur(Node *root, vector<int> &inOrderList)
{
    if(root == NULL)
    {
        return;
    }
    
    inOrderRecur(root->left,inOrderList);
    inOrderList.push_back(root->data);
    inOrderRecur(root->right,inOrderList);
    
    return;
}

vector<int> inOrder(Node *root) {
    // code here
    vector<int> inOrderList;
    
    inOrderRecur(root,inOrderList);
    
    return inOrderList;
}
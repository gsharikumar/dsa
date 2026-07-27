

// User function Template for C++

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    if(root->data == input)
    {
        return root->data;
    }
    int ret;
    if(root->data > input)
    {
        ret = findCeil(root->left, input);
    }else{
        ret = findCeil(root->right, input);
    }
    if(ret == -1)
    {
        if(root->data > input)
        {
            return root->data;
        }
    }
    return ret;
}
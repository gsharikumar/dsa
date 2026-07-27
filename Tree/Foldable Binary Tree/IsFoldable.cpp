/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
bool isFoldableRecur(Node* rootLeft, Node* rootRight)
{
    if(rootLeft == NULL && rootRight == NULL){
        return true;
    }else if(rootLeft == NULL || rootRight == NULL){
        return false;
    }

    return (isFoldableRecur(rootLeft->left, rootRight->right) && \
            isFoldableRecur(rootLeft->right, rootRight->left));
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(root == NULL){
        return true;
    }
    return isFoldableRecur(root->left, root->right);
}
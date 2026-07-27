

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
 #define MIN(L,R) (L<R?L:R)
 #define MAX(L,R) (L>R?L:R)

//Function to return the maximum difference between any node and its ancestor.
int maxDiffRecur(Node* root, int &maxDiffVal)
{
    if(root == NULL){
        return INT_MAX;
    }    
    
    int currVal = root->data;
    int leftMin = maxDiffRecur(root->left,maxDiffVal);
    int rightMin = maxDiffRecur(root->right,maxDiffVal);
    int minChildVal = MIN(leftMin,rightMin);
    if(minChildVal != INT_MAX){
        maxDiffVal = MAX(maxDiffVal, currVal - minChildVal);
    }
    return MIN(currVal,minChildVal);
    
}

int maxDiff(Node* root)
{
    // Your code here 
    int maxDiffVal=INT_MIN;
    int minVal=maxDiffRecur(root,maxDiffVal);
    
    return maxDiffVal;
}
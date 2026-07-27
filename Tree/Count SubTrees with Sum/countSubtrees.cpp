

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
//Function to count number of subtrees having sum equal to given sum.

int countSubTreeWithSumXUtil(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int currSum=0;
    if(root->left){
        currSum += root->left->data;
    }
    if(root->right){
        currSum += root->right->data;
    }
    
    currSum += root->data;
    
    return currSum;
}

int countSubtreeWithSumXRecur(Node* root, int X,int &count)
{
    if(root == NULL)
    {
        return 0;
    }

    int currSum=0;
    int leftCurrSum = countSubtreeWithSumXRecur(root->left,X,count);
    int rightCurrSum = countSubtreeWithSumXRecur(root->right,X,count);

    currSum = root->data + rightCurrSum + leftCurrSum;
    if(currSum == X){
        count++;
    }
    
    return currSum;
    
    
}


int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count = 0;
	countSubtreeWithSumXRecur(root,X,count);
	return count;
}
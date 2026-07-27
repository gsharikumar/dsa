

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minD;
    void getMinDiff(Node *root,int K)
    {
        if(root == NULL){
            return;
        }
        minD=min(minD,abs(root->data - K));
        if(root->data > K)
        {
             getMinDiff(root->left,K);
        }
        else if(root->data < K)
        {
            getMinDiff(root->right,K);
        }
        
        return;
    }

    int minDiff(Node *root, int K)
    {
        //Your code here
        minD = INT_MAX;
        getMinDiff(root,K);
        return minD;
    }
};
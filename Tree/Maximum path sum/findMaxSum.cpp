// User Fuction template for C++
#define MAX(L,R) ((L > R) ? L : R);
class Solution {
    int maxSum;
    int findMaxSumRecur(Node* root, int currSum)
    {
        if(root == NULL){
            return 0;
        }
        int currVal = root->data;
        int currLeftSum = findMaxSumRecur(root->left,currSum);
        int currRightSum = findMaxSumRecur(root->right,currSum);
        //to ignore negative values
        currLeftSum=MAX(0,currLeftSum);
        currRightSum=MAX(0,currRightSum);
        maxSum = MAX(maxSum,currVal + currLeftSum + currRightSum);
        
        return currVal + MAX(currLeftSum, currRightSum);      
    }
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        if(root == NULL){
            return 0;
        }
        maxSum = INT_MIN;
        findMaxSumRecur(root,0);
        return maxSum;
    }
};
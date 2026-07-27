//User function Template for C++

/*Structure of node of binary tree is as follows
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

int maxLeftCnt=0;
int maxRightCnt=0;

void getVerticalWidth(Node* root,int curr){
    if(root==NULL){
        return;
    }
    if(curr<maxLeftCnt) {maxLeftCnt=curr;}
    if(curr>maxRightCnt) {maxRightCnt=curr;}

    getVerticalWidth(root->left,curr-1);
    getVerticalWidth(root->right,curr+1);

    return;
}
//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    // Code here
    if(root==NULL){
        return 0;
    }
    maxLeftCnt=0;
    maxRightCnt=0;
    getVerticalWidth(root,0);
    
    return abs(maxLeftCnt)+maxRightCnt+1;
}
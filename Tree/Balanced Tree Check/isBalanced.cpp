/* A binary tree node structure

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

class Solution{
    public:

    bool isBalancedHeight(Node *root,int *height){
        if(root==NULL){
            return 1;
        }
        int lH=0;//*height;
        int rH=0;//*height;

        bool bL=isBalancedHeight(root->left,&lH);
        bool bR=isBalancedHeight(root->right,&rH);

        *height=((lH>rH?lH:rH)+1);
        
        if(abs(lH-rH)>1){
            return false;
        }
   
        if(!(bL && bR)){
            return false;
        }

        //cout<<*height<<endl;   
        return true; 
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int height=0;
        if(root==NULL){
            return true;
        }
        return isBalancedHeight(root,&height);        
    }
};
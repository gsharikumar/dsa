/*Complete the function below

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
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if( root==NULL || (root->left==NULL && root->right==NULL) ){
         return 1;
     }
     int sum=0;
     if(root->left){
         sum+=root->left->data;
     }
     if(root->right){
         sum+=root->right->data;
     }
     if(sum==root->data){
         int lStatus=1;
         int rStatus=1;
         if(root->left){
            lStatus=isSumProperty(root->left);
         }
         if(root->right){
            rStatus=isSumProperty(root->right);
         }
         //cout<<lStatus<<"&"<<rStatus<<"="<<(lStatus && rStatus);
         return (lStatus && rStatus);
     }
     return 0;
    }
};
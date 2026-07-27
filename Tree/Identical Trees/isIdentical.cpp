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


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1 == r2){
            if(r1==NULL){
                return true;
            }
        }else if(r1==NULL || r2==NULL){
            return false;
        }
        if(r1->data==r2->data){
            bool lState=isIdentical(r1->left,r2->left);
            bool rState=isIdentical(r1->right,r2->right);
            return lState && rState;
        }
        return false;

    }
};
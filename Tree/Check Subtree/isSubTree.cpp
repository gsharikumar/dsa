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
    bool isSimilarRecur(Node *T, Node* S){
        if(T == NULL && S == NULL){
            return true;
        }
        if(T == NULL || S == NULL){
            return false;
        } 
        if(T->data == S->data){
            return (isSimilarRecur(T->left, S->left) && isSimilarRecur(T->right,S->right));
        }
        return false;
    }
    
    bool isSubTreeRecur(Node* T, Node* S){
        
        if(T == NULL && S == NULL){
            return true;
        }
        if(T == NULL || S == NULL){
            return false;
        }

        if(true == isSimilarRecur(T,S)){
            return true;
        }
        bool leftTrack=isSubTreeRecur(T->left,S);
        bool rightTrack=isSubTreeRecur(T->right,S);
        
        
        return leftTrack || rightTrack;
    }
  
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        return isSubTreeRecur(T,S);
        
    }
};
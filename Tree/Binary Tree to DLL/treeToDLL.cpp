/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution
{
    public:
    Node *head=NULL;
    Node *prev=NULL;
    void bToDLLRecur(Node *parent,Node *root){
        
        if(root==NULL){
            return;
        }
        
        bToDLLRecur(root,root->left);
        if(prev){
            prev->right=root;
            root->left=prev; //is it requried ??
            prev=prev->right;
        }else{
            prev=root;
        }
        if(head==NULL){
            head=root;
        }
        bToDLLRecur(root,root->right);

        return;
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here

        bToDLLRecur(NULL, root);
        return head;
    }
};

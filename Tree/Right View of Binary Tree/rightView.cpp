/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    int maxHeight=INT_MIN;
    void getRightView(Node *root,int height,vector<int> &rView){
        if(root==NULL){
            return;
        }
        if(height>maxHeight){
            maxHeight=height;
            rView.push_back(root->data);
        }
        
        getRightView(root->right,height+1,rView);
        getRightView(root->left,height+1,rView);
        return;
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> rView;
       maxHeight=INT_MIN;
       getRightView(root,0,rView);
       return rView;
       
    }
};

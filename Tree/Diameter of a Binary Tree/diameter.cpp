/* Tree node structure  used in the program

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

    int getDiameter(Node *root,int &diameter){
        if(root==NULL){
            return 0;
        }    
        int lDiameter=getDiameter(root->left,diameter);
        int rDiameter=getDiameter(root->right,diameter);
        int maxDiameter;
        if(lDiameter>rDiameter){
            maxDiameter=lDiameter;
        }else{
            maxDiameter=rDiameter;
        }
        
        if((lDiameter+rDiameter+1) > diameter){
            diameter=lDiameter+rDiameter+1;
        }

        return maxDiameter+1;
    }
    
    
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int diameter=0;
        getDiameter(root,diameter);
        return diameter;
    }
};
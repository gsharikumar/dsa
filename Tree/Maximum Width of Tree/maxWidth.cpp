/*  Structure of a Binary Tree

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

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        queue<Node*> q;
        int maxWidth=0;
        if(root==NULL){
            return maxWidth;
        }
        
        q.push(root);
        
        while(!q.empty()){
            int qSize=q.size();
            maxWidth=(maxWidth<qSize)?qSize:maxWidth;
            while(qSize--){
                Node *n=q.front();
                q.pop();
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
                
            }
        }
        return maxWidth;
    }
};
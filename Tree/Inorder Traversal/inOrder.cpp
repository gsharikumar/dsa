/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    void inOrderTraversal(Node* root,vector<int> &inOrderList){
        if(root==NULL){
            return;
        }
        if(root->left){
            inOrderTraversal(root->left,inOrderList);
        }
        
        inOrderList.push_back(root->data);

        if(root->right){
            inOrderTraversal(root->right,inOrderList);
        }
        return;
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> inOrderList;
        inOrderTraversal(root,inOrderList);
        return inOrderList;
    }
};
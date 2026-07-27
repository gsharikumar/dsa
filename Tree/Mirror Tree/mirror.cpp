// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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

class Solution {
  public:
    void mirrorRecur(Node *node){
        if(node==NULL){
            return;
        }
        //swap left and right
        Node* tmp=node->left;
        node->left=node->right;
        node->right=tmp;
        mirrorRecur(node->left);
        mirrorRecur(node->right);
        return;
    }
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        mirrorRecur(node);
        return;
    }
};
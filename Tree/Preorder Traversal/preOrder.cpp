

/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
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

void preOrderTraversal(Node* root,vector<int> &preOrderList){
    if(!root){
        return;
    }
    preOrderList.push_back(root->data);
    
    if(root->left){
        preOrderTraversal(root->left,preOrderList);        
    }
    if(root->right){
        preOrderTraversal(root->right,preOrderList);        
    }
    return;
}

//Function to return a list containing the preorder traversal of the tree.
vector<int> preorder(Node* root)
{
  // Your code here
  vector<int> preOrderList;
  preOrderTraversal(root,preOrderList);
  return preOrderList;
}
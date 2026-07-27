

//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
void postOrder(Node *root,vector<int> &postOrderList){
    if(root==NULL){
        return;
    }
    if(root->left){
        postOrder(root->left,postOrderList);
    }
    if(root->right){
        postOrder(root->right,postOrderList);
    }
    postOrderList.push_back(root->data);

    return;
}
//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
  vector <int> postOrderList;
  postOrder(root,postOrderList);
  return postOrderList;
}
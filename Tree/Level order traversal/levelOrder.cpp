/* A binary tree Node

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
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> levelOrderList;
      queue <Node*> q;
      if(node==NULL){
          return levelOrderList;
      }
      
      q.push(node);
      while(!q.empty()){
          Node *curr=q.front();
          levelOrderList.push_back(curr->data);
          q.pop();
          if(curr->left){
              q.push(curr->left);
          }
          if(curr->right){
              q.push(curr->right);
          }
      }
      return levelOrderList;
    }
};
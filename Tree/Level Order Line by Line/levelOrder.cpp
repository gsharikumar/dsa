

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

//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q;
  vector<vector<int>> levelOrderList;
  if(node==NULL){
      return levelOrderList;
  }
  
  q.push(node);
  vector<int> tQ(1,node->data);
  levelOrderList.push_back(tQ);
  while(!q.empty()){
      int qSize=q.size();
      vector<int> sQ;
      while(qSize!=0){
          Node *curr=q.front();
          q.pop();
          if(curr->left){
            sQ.push_back(curr->left->data);
            q.push(curr->left);
          }
          if(curr->right){
            sQ.push_back(curr->right->data);
            q.push(curr->right);
          }
          qSize--;
      }
      if(sQ.size()>0){
        levelOrderList.push_back(sQ);
      }
  }
  return levelOrderList;
  
}

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(root == NULL){
           return;
       }
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
            int qSize=q.size();
            Node *prev=NULL;
            for(int i=0;i<qSize;i++)
            {
                Node* c=q.front();
                q.pop();
                if(prev){
                    prev->nextRight=c;
                    prev=c;
                }
                prev=c;
                
                c->nextRight=NULL;
                if(c->left){
                    q.push(c->left);               
                }
                if(c->right){
                    q.push(c->right);               
                }
            
            }
       }
    }    
      
};


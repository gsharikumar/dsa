

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


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> spiralTraversal;
    queue<Node*> q;
    stack<int> s;
    bool reverse=true;
    if(root==NULL){
        return spiralTraversal;
    }
    
    q.push(root);
    
    
    while(!q.empty()){
        int qS=q.size();
        while(qS){
            Node *n=q.front();
            q.pop();
            if(reverse==true){
                //if even left first and then right
                s.push(n->data);
            }else{
                spiralTraversal.push_back(n->data);
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
            qS--;
        }
        if(reverse==true){
            while(!s.empty()){
                spiralTraversal.push_back(s.top());
                s.pop();
            }
        }
        reverse=!reverse;
    }
    return spiralTraversal;
}
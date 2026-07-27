

/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
int maxLevel=0;
void getLeftView(Node *root,int level,vector<int> &lv){
    if(root==NULL){
        return;
    }
    if(maxLevel<level){
        maxLevel=level;
        lv.push_back(root->data);
    }

    getLeftView(root->left,level+1,lv);
    getLeftView(root->right,level+1,lv);
    return;
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> lv;
   maxLevel=0;
   getLeftView(root,1,lv);
   return lv;
}
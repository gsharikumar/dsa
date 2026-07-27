

/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.

struct TreeNode *createTreeNode(int data){
    TreeNode* tn=(TreeNode*)malloc(sizeof(TreeNode));
    tn->data=data;
    tn->left = tn->right = NULL;
    return tn;
}
void addNode2Tree(Node *&ll,TreeNode *&root){
    if(ll == NULL){
        return;
    }
    root = createTreeNode(ll->data);
    return;
}

void convert(Node *head, TreeNode *&root) {
    // Your code here
    
    root=NULL;
    if(head == NULL){
        return;
    }

    queue <TreeNode*> q;
    Node* currLL=head;

    root=createTreeNode(currLL->data);
    q.push(root);

    while(!q.empty()){
        TreeNode* tn = q.front();
        q.pop();
        
        if(currLL){
            if(currLL->next){
                currLL=currLL->next;
                tn->left=createTreeNode(currLL->data);
                q.push(tn->left);
            }
            if(currLL->next){
                currLL=currLL->next;
                tn->right=createTreeNode(currLL->data);
                q.push(tn->right);
            }
        }
    }
    return;
}
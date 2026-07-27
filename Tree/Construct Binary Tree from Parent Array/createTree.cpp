/* node structure  used in the program

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

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createNode(int data){
        Node* node=(Node*)calloc(1,sizeof(Node*));
        node->data=data;
        
    }
    Node *createTree(int parent[], int N)
    {
        // Your code here
        Node *head=NULL;
        Node **nodeArray=(Node **)calloc(N,sizeof(Node*));
        for(int i=0;i<N;i++){
            nodeArray[i]=createNode(i);    
        }
        for(int i=0;i<N;i++){
            if(parent[i]>-1){
                Node* parentNode =nodeArray[parent[i]];
                if(parentNode->left){
                    parentNode->right=nodeArray[i];
                }else{
                    parentNode->left=nodeArray[i];
                }
            }else{
                head=nodeArray[i];
            }
        }
        return head;
    }
};
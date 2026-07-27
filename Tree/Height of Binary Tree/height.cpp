//User function template for C++

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
class Solution{
    public:
    
    int heightBT(struct Node* node){
        int lH=0;
        int rH=0;
        if(node==NULL){
            return 0;
        }
        if(node->left){
            lH=heightBT(node->left)+1;
        }
        if(node->right){
            rH=heightBT(node->right)+1;
        }
        return ((lH>rH)?lH:rH);
    }
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        int h=0;
        if(node){
            h=heightBT(node);
            h++;
        }
        return h;
    }
};
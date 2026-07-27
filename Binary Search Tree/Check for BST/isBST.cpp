class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.

    bool isBSTRecur(Node* root,int min,int max) 
    {
        // Your code here
        if(root == NULL)
        {
            return true;
        }

        bool cond = (root->data > min) && (root->data < max) ;
        bool left= isBSTRecur(root->left,min,root->data);
        bool right= isBSTRecur(root->right,root->data,max);
        
        return left && right && cond;

    }
    
    bool isBST(Node* root) 
    {
        return isBSTRecur(root,INT_MIN,INT_MAX);
        
    }
};


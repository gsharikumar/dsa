//User function template for C++

class Solution {
  public:
  
    void printNearNodesRecur(Node *root, int low, int high,vector<int> &vec)
    {
        if(root == NULL)
        {
            return;
        }
        printNearNodesRecur(root->left,low,high,vec);
        if(low <= root->data && high >= root->data)
        {
            vec.push_back(root->data);
        }
        printNearNodesRecur(root->right,low,high,vec);
        return;
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here   
        vector<int> vec;
        printNearNodesRecur(root, low, high,vec);
        return vec;
    }
};
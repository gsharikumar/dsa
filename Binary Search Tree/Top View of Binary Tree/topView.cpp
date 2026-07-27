/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> vec;
        queue< pair<Node*,int> > q;
        
        if(root == NULL)
        {
            return vec;
        }
        
        q.push({root,0});
        
        map<int,vector<int>> hash;
        while(!q.empty())
        {
            Node *n=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(hash[dist].empty() == true)
            {
                hash[dist].push_back(n->data);
            }
            if(n->left)
            {
                q.push({n->left,dist-1});
            }
            if(n->right)
            {
                q.push({n->right,dist+1});
            }
        }
        for (std::map<int,vector<int>>::iterator it=hash.begin(); it!=hash.end(); ++it)
        {
            vector<int> *v = &it->second;
            vec.push_back((*v)[0]);
        }
        return vec;
    }

};

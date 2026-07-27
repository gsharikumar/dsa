class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    void prepareVerticalMap(Node *root, int dist,map<int,vector<int>> &hash)
    {
        if(root == NULL)
        {
            return;
        }
        hash[dist].push_back(root->data);
        prepareVerticalMap(root->left,dist-1,hash);
        prepareVerticalMap(root->right,dist+1,hash);
        return;
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> vec;
        if(root == NULL)
        {
            return vec;
        }
        map<int,vector<int>> hash;
        
        //prepareVerticalMap(root,0,hash);  - here node apearing on the top wont come first
        //level order traversal, as the noe on the top must appear fist
        queue <pair<Node*,int>> q;
        q.push({root,0});
        hash[0].push_back(root->data);
        
        while(!q.empty())
        {
            Node *n=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(n->left)
            {
                q.push({n->left,dist-1});
                hash[dist-1].push_back(n->left->data);
            }
            if(n->right)
            {
                q.push({n->right,dist+1});
                hash[dist+1].push_back(n->right->data);
            }
        }
        std::map<int,vector<int>>::iterator it = hash.begin();
        // Iterate over the map using Iterator till end.
        while (it != hash.end())
        {
            vector<int> *v = (vector<int>*)&it->second;
            vec.insert(std::end(vec), std::begin(*v), std::end(*v));
            it++;
        }
        return vec;
    }
};

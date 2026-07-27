//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    void bottemViewRecur(Node *root,map<int,vector<int>> &hash,int dist)
    {
        if(root == NULL)
        {
            return;
        }
        if(hash[dist].empty() == true){
            hash[dist].push_back(root->data);
        }else{
            hash[dist][0]=root->data;
        }

        bottemViewRecur(root->left,hash,dist-1);
        bottemViewRecur(root->right,hash,dist+1);

        return;
        
    }
    
    
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector <int> vec;
        
        if(root == NULL)
        {
            return vec;
        }
        map<int,vector<int>> hash;
        
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            Node *n = q.front().first;
            int dist = q.front().second;
            q.pop();
            hash[dist].push_back(n->data);
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
            vector<int> *v=&it->second;    
            vec.push_back((*v).back());
        }
        return vec;
    }
};
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

class Solution
{
    public:
    int N1;
    int N2;
    Node *getLCA(Node *root){
        if(root==NULL){
            return NULL;
        }
        if(root->data == N1 || root->data == N2){
            return root;
        }
        Node *lN=getLCA(root->left);
        Node *rN=getLCA(root->right);
        
        if(lN != NULL && rN != NULL){
            return root;
        }
        
        if(lN!=NULL){
            return lN;
        }else{
            return rN;
        }
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        N1=n1;
        N2=n2;
        return getLCA(root);
    }
    
/********************Brute-not complete****************************/        
    bool getLCSBrute(Node *root,int n,vector<Node*> &path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root->data == n){
            return true;
        } 
        bool ls=getLCSBrute(root->left,n,path);
        bool rs=getLCSBrute(root->right,n,path);
    
        if( ls == true || rs == true ){
            return true;
        }

        path.pop_back();
        return false;
    
    }

    Node* lcaBruteForceNotWorking(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
        if(root == NULL){
           return NULL;
        }

        vector<Node*> path1;
        vector<Node*> path2;
        bool ls=getLCSBrute(root,n1,path1);
        bool rs=getLCSBrute(root,n2,path2);

        if(ls==false || rs==false){
            return NULL;
        }

        int p1Size=path1.size();
        int p2Size=path2.size();
        Node *lca=NULL;

        int i=0;
        int pSize=(p1Size>p2Size)?p2Size:p1Size;
        while(i < pSize-1){
            if(path1[i+1]!=path2[i+1]){
                lca=path2[i];
                break;
            }
            i++;
        }
        
       return lca;
    }
};
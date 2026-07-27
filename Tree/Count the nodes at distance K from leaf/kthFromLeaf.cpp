

//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/


//Function to return count of nodes at a given distance from leaf nodes.
#define MIN(l,r) (l<r?l:r)
#define MAX(l,r) (l>r?l:r)
int countRet = 0;
int printKDistFromLeafRecur(Node* root, int k,vector<int> &vec,vector<bool> &visited)
{
    if(root == NULL){
       return 1;
    } 
    int vecSize;
    int idx;
    vec.push_back(root->data);
    visited.push_back(false);
    
    int isRoot=1;
    isRoot &= printKDistFromLeafRecur(root->left,k,vec,visited);
    isRoot &= printKDistFromLeafRecur(root->right,k,vec,visited);
    
    if(isRoot){
        vecSize = vec.size();
        idx = vecSize - k - 1;
        if(idx >= 0 && visited[idx] == false){
            visited[idx] = true;
            countRet++;
        }
    }    
    vec.pop_back();
    visited.pop_back();

   return 0; 

}

int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here. 
	countRet = 0;
    vector<int> vec;
    vector<bool> visited;
	printKDistFromLeafRecur(root,k,vec,visited);
	return countRet;
}
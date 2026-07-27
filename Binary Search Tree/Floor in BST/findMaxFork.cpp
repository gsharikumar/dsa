// User function Template for C

int Floor(struct Node* root, int key) {
    // your code here
    if(root == NULL){
        return -1;
    }
    if(root->data == key)
    {
        return root->data; 
    }
    int ret;
    if(root->data > key)
    {
        ret = Floor(root->left,key);    
    }else{
        ret = Floor(root->right,key);
    }
    if(ret == -1)
    {
        //exact match is not found
        if(root->data < key){
            return root->data;
        }
    }
    return ret;
}
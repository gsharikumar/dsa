

// Function to delete a node from BST.
Node *deleteThisNode(Node *root)
{
        
}

Node *findNode(Node *root, int X,Node *&parent)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->data > X)
    {
        Node *n = findNode(root->left,X,parent);
        if(n)
        {
            if(parent == NULL)
            {
                parent = root;
            }
            return n;
        }
    }
    else if(root->data < X)
    {
        Node *n = findNode(root->right,X,parent);
        if(n)
        {
            if(parent == NULL)
            {
                parent = root;
            }
            return n;
        }

    }
    else
    {
        return root;
    }
}

void getInOrder(Node *root,vector<int> &inOrderList)
{
    if(root == NULL)
    {
        return;
    }
    getInOrder(root->left,inOrderList);
    inOrderList.push_back(root->data);
    getInOrder(root->right,inOrderList);
    
    return;    
}

Node *deleteNode(Node *root, int X) {
    // your code goes here
    Node* parent = NULL;
    Node* delNode = findNode(root,X,parent);
    if(delNode != NULL)
    {
        if(delNode->left && delNode->right)
        {
            vector <int> inOrderList;
            getInOrder(delNode,inOrderList);
            int idx = 0;
            int len = inOrderList.size();
            while(idx < len)
            {
                if(inOrderList[idx] == X)
                {
                    break;
                }
                idx++;
            }
            int tmp = inOrderList[idx+1];
            delNode->data = tmp;         
            delNode->right = deleteNode(delNode->right,tmp);
 
        }
        else if(parent == NULL)
        {
            root = NULL;
        }
        else if(delNode->left || delNode->right)
        {
            //has child node
            if(parent->left)
            {
                if(parent->left->data == X)
                {
                    parent->left = delNode->left;
                }
            }
            else
            {
                if(parent->right->data == X)
                {
                    parent->right = delNode->right;
                }
            }
            //free(delNode);
        }else
        {
            //is a leaf node
            if(parent->left)
            {
                if(parent->left->data == X)
                {
                    parent->left = NULL;
                }
            }else
            {
                if(parent->right->data == X)
                {
                    parent->right = NULL;
                }
            }
            //free(delNode);
        }
    }
    
    return root;
}


//Function to check if any pair exists in BST whose sum is equal to given value.
void getInorder(Node* root, vector<int> &vec)
{
    if(root == NULL)
    {
        return;
    }
    getInorder(root->left,vec);
    vec.push_back(root->data);
    getInorder(root->right,vec);
    return;
}

bool findPair(Node* root, int X) 
{
    // Your code here
    vector<int> vec;
    //get Inorder of BST, which provides sorted list
    getInorder(root,vec);
    //find if pair sum X exists in the sorted list
    int l=0;
    int h=vec.size()-1;
    bool bRet = false;
    while(l<h)
    {
        int sum = vec[l]+vec[h];
        if(sum == X)
        {
            bRet = true;
            break;
        }
        else
        {
            if(sum < X)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
    }
    return bRet;
}


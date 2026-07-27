

class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> cList;
    vector <int> cList1;
    vector <int> cList2;
/* first attempt - complete wrong approach
    void findCommonRecur(Node *root1, Node *root2)
    {
        if(root1  == NULL || root2 == NULL)
        {
            return;
        }
        if(root1->data < root2->data)
        {
            findCommonRecur(root1->right,root2);
            findCommonRecur(root1,root2->left);
        }
        else if(root1->data > root2->data)
        {
            findCommonRecur(root1->left,root2);
            findCommonRecur(root1,root2->right);
        }
        else
        {
            cList.push_back(root1->data);
            findCommonRecur(root1->left,root2->left);
            findCommonRecur(root1->right,root2->right);
        }
        return;
    }
    */
    
    void prepareInorderList(Node *root,vector<int> &list)
    {
        if(root  == NULL)
        {
            return;
        }
        prepareInorderList(root->left,list);
        list.push_back(root->data);
        prepareInorderList(root->right,list);
        
        return;
    }        
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
        cList.clear();
        cList1.clear();
        cList2.clear();
        prepareInorderList(root1,cList1);
        prepareInorderList(root2,cList2);
        int l1=0;
        int l2=0;
        
        while(l1 < cList1.size() && l2 < cList2.size())
        {
            if(cList1[l1] < cList2[l2])
            {
                l1++;
            }
            else if(cList1[l1] > cList2[l2])
            {
                l2++;    
            }
            else
            {
                cList.push_back(cList1[l1]);
                l1++;
                l2++;
            }
        }
        return cList;
    }
};


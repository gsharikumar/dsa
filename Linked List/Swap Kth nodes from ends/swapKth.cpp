/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        //find total nodes in the list
        int i;
        Node* leftNode;
        Node* rightNode;
        int count = 0;
        Node *curr = head;
        while(curr)
        {
            count++;
            curr= curr->next;
        }
        /*
        1 2 3 4 5
        k 2
        
        */
        int left = k;
        int right = count - k + 1;
        //cout << count <<"--"<<left<<"--"<<right<<endl;
        if((left < 0 || left > count) || (right < 0 || right > count))
        {
            return head;
        }

        Node *lnode = head;
        leftNode = head;
        i = left;
        while(lnode && i)
        {
            i--;
            leftNode = lnode;
            //cout << leftNode->data <<endl;
            lnode = lnode->next;
        }
        
        Node *rnode = head;
        rightNode = head;
        i = right;
        while(rnode && i)
        {
            i--;
            rightNode = rnode;
           // cout << rightNode->data <<endl;
            rnode = rnode->next;
        }
        
        int tmp = rightNode->data;
        rightNode->data = leftNode->data;
        leftNode->data = tmp;
        return head;
    }
};
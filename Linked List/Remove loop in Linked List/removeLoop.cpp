/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  
  /*
  1 3 4
  
  s=1, f=4, p = 1
  
  s=3, f=4, p=4
  
  s=4, f=4, p=4
  
  
  1 2 3 4
  
  S=1, F=3 P=1
  S=2,F=1,P=3
  S=3,F=3,P=1
  */

    void removeLoop(Node* head) {
        // code here
        Node *slow = head;
        Node *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                if(head == fast)
                {
                    while(slow != fast->next)
                    {
                        fast = fast->next;
                    }
                    fast->next = NULL;
                }
                else
                {
                    while(slow->next != fast->next)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    fast->next = NULL;
                }
                break;
            }
        }
        
    }
};
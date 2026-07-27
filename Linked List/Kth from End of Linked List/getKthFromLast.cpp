/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node *curr = head;
        int n = 0;
        while(curr)
        {
            n++;
            curr = curr->next;
        }
        
        if(k > n)
        {
            return -1;
        }
        
        int right = n - k + 1;
        
        if(right <= 0 && right > n)
        {
            return -1;
        }
        Node *prev = NULL;
        curr = head;
        while(curr && right)
        {
            right--;
            prev = curr;
            curr = curr->next;
        }
        
        return prev->data;
    }
};
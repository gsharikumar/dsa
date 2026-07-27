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

/*
1 2 3 4 5 6 7 8 9 10

1 - 1 = 0
2 - 3 = 1
3 - 5 = 2
4 - 7 = 3
5 - 9 = 4
6 - 11 = 5
*/
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head;
        Node *fast = head;
        int slow_idx = 0;
        int fast_idx = 0;
        int dist = 0;
        bool loop_found = false;
        while(slow && (fast && fast->next))
        {
            slow = slow->next; slow_idx+=1;
            fast = fast->next->next; fast_idx+=2;
            if(slow == fast)
            {
                Node *curr = slow->next;
                while(curr)
                {
                    dist++;
                    if(curr == fast)
                    {
                        break;
                    }
                    curr =  curr->next;
                }
                loop_found = true;
                break;
            }
        }
        //return (loop_found ? (fast_idx - slow_idx): 0);
        return dist;
    }
};
/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    void revLL(Node** head)
    {
        Node *front = NULL;
        Node *back = NULL;
        Node *curr = *head;
        while(curr != NULL)
        {
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        *head = back;
        return;    
    }
    void printLL(Node *head)
    {
        while(head != NULL)
        {
            cout<<head->data<<" , ";
            head = head->next;
        }
        cout<<endl;
    }
    
    void removeLeadingZeros(Node **head)
    {
        Node *curr = *head;
        while(curr != NULL)
        {
            if(curr->data == 0)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            else
            {
                break;
            }
        }
        *head = curr;
    }
    
    
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        revLL(&head1);
       // printLL(head1);
        revLL(&head2);
       // printLL(head2);
        int carry = 0;
        int data1;
        int data2;
        int rem;
        int sum;
        Node *retLL;
        
        Node *sumLL = NULL; 
        while(head1!=NULL || head2!=NULL)
        {
            data1= 0;
            data2= 0;
            
            if(head1)
            {
                data1 = head1->data;
                head1= head1->next;
            }
            if(head2)
            {
                data2 = head2->data;
                head2 = head2->next;
            }
            sum = data1 + data2 + carry;
            rem = sum % 10;
            carry = floor(sum/10);
            if(sumLL == NULL)
            {
                retLL = sumLL = new Node(rem);
            }
            else
            {
                sumLL->next = new Node(rem);
                sumLL = sumLL->next;
            }
        }
        if(carry)
        {
            sumLL->next = new Node(carry);
        }
        revLL(&retLL);
        removeLeadingZeros(&retLL);
        return retLL;
    }
};
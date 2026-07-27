//User function Template for C

struct Node* reverseList(struct Node *head)
    {
        struct Node* prev=NULL;
        struct Node* curr=NULL;
        struct Node* next=NULL;
        curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(prev)
            return prev;
        else
            return head;
    }
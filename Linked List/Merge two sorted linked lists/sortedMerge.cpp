//User function Template for C

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node *aa=a;
    struct Node *bb=b;
    struct Node *head=NULL;
    struct Node *up=NULL;
    struct Node *fnd=NULL; 
    struct Node *ap=a;
    while(aa || bb){
        if(aa && bb){
            if(aa->data<bb->data){
                fnd=aa;
                aa=aa->next;
            }else{
                fnd=bb;
                bb=bb->next;
            }                
        }else if(aa){
            fnd=aa;
            aa=aa->next;
        }else if(bb){
            fnd=bb;
            bb=bb->next;
        }
        if(!head){
            up=head=fnd;
        }else{
            up->next=fnd;
            up=fnd; //up=up->next; is wrong
        }
        
    }
    return head;
}
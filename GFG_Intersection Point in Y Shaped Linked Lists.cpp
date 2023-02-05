class Solution
{
public:
int intersectPoint(Node* head1, Node* head2)
 {
        // Your Code Here
        Node *p1=head1,*p2=head2;
        while(p1 || p2)
        {
            if(p1==p2) return p1->data;
            if(p1==NULL) p1=head2;
            if(p2==NULL) p2=head1;
            p1=p1->next;
            p2=p2->next;
        }
        return -1;
 }
};

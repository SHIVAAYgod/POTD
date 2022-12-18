class Solution{
public:
    ListNode *moveToFront(ListNode *head){
      if(head->next==NULL) return head;
      ListNode *temp=head;
      ListNode *loop=head;
      
      while(loop->next->next!=NULL)
      {
        loop=loop->next;
      }
      int num=loop->next->val;
      loop->next=NULL;
      ListNode *tmp1=new ListNode(num);
      head=tmp1;
      tmp1->next=temp;
      return head;
    }
};

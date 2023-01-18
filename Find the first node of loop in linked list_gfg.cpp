class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
         unordered_map<Node*,int>m1;
      Node*temp=head;
      m1[temp]++;
      while(temp->next!=NULL)
      {
          temp=temp->next;
          if(m1[temp])
          return temp->data;
          else
          m1[temp]++;   
      } 
      return -1;
    }
};


 ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        int l = 0;
   // calculate length
        while(temp != NULL)
        {
            temp = temp->next;
            l++;
        }
        if(l<k)
        {
            return head;
        }
   // dummynode to handle basecase
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
       
        while(l>=k)
        {
          // head of kth-group
             temp = prev->next;
             ListNode* nextnode = temp->next;
          // have to reverse k-1 links
            for(int i=1;i<k;i++)
            {
              // reverse direction of two nodes
                temp->next = nextnode->next;
                nextnode->next = prev->next;
              // point prev next to second node, we need lasr node to point to prev next
                prev->next = nextnode;
              // move forward 
                nextnode = temp->next;
            }
          // prevhead of kth group as prev
            prev = temp;
            l = l-k;
        }
        return dummy->next;
    }

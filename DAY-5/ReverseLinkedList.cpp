// recursive solution O(n), recursion stack

ListNode* reverseList(ListNode* head) {
      // 1->2->3->4->5->NULL
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newhead = reverseList(head->next);
       // 1->2<-3<-4<-5
       // head->next = 2
        head->next->next = head;
      // 1<-2<-3<-4<-5
        head->next = NULL;
   // 5
        return newhead;
    }

// iterative O(N), O(1)
 ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head->next;
        // change head 
        head->next = NULL;
        while(temp&& temp ->next)
        {
          // store nextelement
            ListNode* nextnode = temp->next;
          // add temp to previous
            temp->next = head;
          // reassign
            head = temp;
            temp = nextnode;
        }
   // add last element to list
   // and return as new head
        temp->next = head;
        return temp;
    }

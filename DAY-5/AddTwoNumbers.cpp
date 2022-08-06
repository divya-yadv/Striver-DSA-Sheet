ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* head  = NULL;
        ListNode* temp  = NULL;
        int carry = 0;
        while(carry || l1 || l2)
        {
            
            int p1 = 0;
            int p2 = 0;
            if(l1)
            {
                p1 = l1->val;
                l1 = l1->next;
            }
             if(l2)
            {
                p2 = l2->val;
                l2 = l2->next;
            }
            int value = p1+p2+carry;
            ListNode* add = new ListNode((value)%10) ;
            carry = value/10;
            if(head == NULL)
            {
                head = add;
                temp = add;
            }
            else
            {
                 temp->next = add;
                 temp = temp->next;
            }
            
        }
        if(temp)
        {
            temp->next = NULL;
        }
        return head;
    }

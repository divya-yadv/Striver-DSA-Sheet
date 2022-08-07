bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
       // check if they meet at a point
        do{
                 slow = slow->next;
                 fast = fast->next->next;
        }while(fast != slow && fast  && fast->next);
        if(fast == slow && fast!=NULL)
        {
            return true;
        }
        return false;
    }

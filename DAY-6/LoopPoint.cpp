ListNode *detectCycle(ListNode *head) {
       ListNode* slow = head;
        ListNode* fast  = head;
        while(fast && fast ->next)
        {
            slow = slow ->next;
            fast = fast ->next ->next;
            if(fast == slow)
                break;
        }
  // check if cycle is there
        if(!fast || !fast->next)
            return NULL;
  // if starting point is cycle point only
        if(slow == head)
            return head;
  // or start loop again where ever meet that's the answer
        fast = head;
        while(slow->next !=  fast->next)
        {
            fast = fast ->next;
            slow = slow ->next;
        }
        return slow ->next;
    }

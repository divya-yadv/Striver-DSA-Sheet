ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
  // move fast pointer two steps two reach the slowest one at the middle
        while(fast && fast->next)
        {
            fast = fast->next;
            if(fast->next)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    

// store list in array and check O(N), 0(N)

//o(N)
ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp)
        {
            ListNode* add = temp->next;
            temp->next = prev;
            prev = temp;
            temp = add;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* part2 = head;
        ListNode* part1 = head;
        if(part1 == NULL || part1->next == NULL)
        {
            return true;
        }
      // got till half part
        while(part1->next && part1->next->next)
        {
            part2 = part2 ->next;
            part1 = part1->next->next;
        }
        part1 = head;
      // reverse half part
        part2 = reverseList(part2->next);
      // now do comparison
        while(part2)
        {
            if(part1->val != part2->val)
            {
                return false;
            }
            part1 = part1->next;
            part2 = part2->next;
        }
        return true;
    }

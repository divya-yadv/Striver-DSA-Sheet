ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 != NULL && list2 == NULL)
        {
            return list1;
        }
        if(list1 == NULL && list2 != NULL)
        {
            return list2;
        }
        if(!list1 && !list2)
        {
            return NULL;
        }
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(a && b)
        {
            if(a->val <= b->val)
            {
                if(head == NULL)
                {
                    head = a;
                    tail = a;
                }
                else
                {
                    tail->next = a;
                    tail = tail->next;
                }
                a = a->next;
            }
            else
            {
                 if(head == NULL)
                {
                    head = b;
                    tail = b;
                }
                else
                {
                    tail->next = b;
                    tail = tail->next;
                }
                 b = b->next;
            }
        }
        if(a)
        {
            tail->next = a;
        }
        if(b)
        {
            tail->next = b;
        }
        return head;
    }

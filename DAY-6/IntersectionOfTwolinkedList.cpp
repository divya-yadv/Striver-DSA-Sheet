
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB)
            return headA;
        else if((headA == NULL) || (headB == NULL))
            return NULL;
        ListNode* A = headA;
        ListNode* B = headB;
        while(A || B)
        {
            if(A == B)
                return A;
          // here we will travserse two times max to reach intersection, when we initialize second time it covers rest of length of longer list and both become equal
            else if(A == NULL)
                A = headB;
            else if(B == NULL)
                B = headA;
            else
            {
                A = A->next;
                B = B->next;
            }
        }
        return NULL;
    }

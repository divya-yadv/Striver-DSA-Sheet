ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while(n && temp)
        {
            temp = temp->next;
            n--;
        }
  // if n greater than length
        if(n)
        {
            return head;
        }
  // if it asked to delete head
        if(temp == NULL)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
  // get prev node of the node that needs to be deleted
        ListNode* prevdel = head;
        while(temp->next)
        {
            temp = temp->next;
            prevdel = prevdel ->next;
        }
        ListNode* nodetobedeleted = prevdel->next;
        prevdel->next = prevdel->next->next;
        delete nodetobedeleted;
        return head;
    }

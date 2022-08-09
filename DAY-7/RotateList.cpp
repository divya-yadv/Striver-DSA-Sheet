
ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* newhead=NULL;
        ListNode* slow = head;
        ListNode* temp = head;
        int len = 1;
  // get the last element and join it to head and also get the length
        while(temp->next!=NULL)
        {
            temp = temp->next;
            len++;
        }
  // calculate the shifting 
        k = len-1-k%len;
        temp->next = head;
        temp = head;
  // travserse len-1-k to get the newhead
        while(k && temp)
        {
            temp = temp->next;
            k--;
        }
        head = temp->next;
  // break the loop
        temp->next = NULL;
        return head;
    }

void deleteNode(ListNode* node) {
  // swap value with next one and delete that
        ListNode* nextnode = node->next;
        node ->val = nextnode->val;
        node->next = node->next->next;
        delete nextnode;
    }

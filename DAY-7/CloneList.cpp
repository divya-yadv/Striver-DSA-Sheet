// O(3*N) three traversal
Node* copyRandomList(Node* head) {
        if(head == NULL)
        {
            return NULL;
        }
        Node* temp = head;
        // copy all nodes and make copied node the next of original node
        while(temp)
        {
            Node* nextnode = new Node(temp->val);
            nextnode->next = temp->next;
            temp->next = nextnode;
            temp = temp->next->next;
        }
        temp = head;
        // point the random pointers for copied list
        while(temp)
        {
            if(temp->random != NULL)
                 temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        // seperate both lists
        Node* newhead = head->next;
        Node* l2;
        while(temp)
        {
            l2 = temp->next;
            temp->next = l2->next;
            if(l2->next != NULL)
                l2->next = l2->next->next;
            temp = temp->next;
        }
        return newhead;
    }


// O(N),O(N)
Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        Node* newlist = new Node(-1);
        Node* x = newlist;
        while(temp)
        {
            Node* newnode = new Node(temp->val);
            newlist->next = newnode;
            mp[temp] = newnode;
            temp = temp->next;
            newlist = newlist->next;
        }
        temp = head;
        newlist = x->next;
        while(temp)
        {
            if(temp->random != NULL)
            {
                newlist->random = mp[temp->random];
            }
            temp = temp->next;
            newlist= newlist->next;
        }
        return x->next;
    }

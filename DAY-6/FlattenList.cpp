// we can minheap to sort

//O(N*(N*M)) ->merging N lists that has nodes N*M,
//O( N*M) ->store all in recursion stack
Node* merge (Node* root1, Node* root2)
{
    if(!root1 && root2 )
        return root2;
    if(root1 && !root2 )
        return root1;
    if(!root1 && !root2)
        return NULL;
        
    Node* head = NULL;
    Node* tail = NULL;
    while(root1 && root2)
    {
        if(root1->data <= root2->data)
        {
            if(head == NULL)
            {
                head = root1;
                tail = root1;
            }
            else
            {
                tail->bottom = root1;
                tail = tail->bottom;
            }
            root1 = root1->bottom;
        }
        else
        {
             if(head == NULL)
            {
                head = root2;
                tail = root2;
            }
            else
            {
                tail->bottom = root2;
                tail = tail->bottom;
            }
            root2 = root2->bottom;
        }
    }
    if(root1)
        tail->bottom = root1;
    if(root2)
         tail->bottom = root2;
    return head;
}
Node *flatten(Node *root)
{
   if(root == NULL || root ->next == NULL)
   {
       return root;
   }
  // first flatten rest of the list
   root->next = flatten(root->next);
  // then merge both bottom list
   return merge(root,root->next);
}

// we can minheap to sort
// first push all N nodes using next
// now minimum will be out first node
// push bottom nodes, here if bottom is lesses for all of them it will be out next node otherwise some next pointer will be 
// O(N*M*logN)
//O(N) -> N nodes max at a time
void flatten(Node* root)
{
    priority_queue<Node*, vector<Node*>, mycomp> p;
  //pushing main link nodes into priority_queue.
    while (root!=NULL) {
        p.push(root);
        root = root->next;
    }
    
    while (!p.empty()) {
      //extracting min
        auto k = p.top();
        p.pop();
      //printing  least element 
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
     
}

// for tow lists merge -> O(N+M)
// here we will be traversing all N , 2M, 3M, 4M ....N times == M(2+3+4+5 --N) = (N*N*M)
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

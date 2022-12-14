
// FOR LEFT VIEW
// do level order traversal and get the first element at each level

vector<int> leftView(Node *root)
{
    vector<int>res;
    if(root == NULL)
        return res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        // will push first element
        res.push_back(q.front()->data);
        while(count--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp ->right)
            {
                q.push(temp->right);
            }
        }
    }
    return res;
}

// recursive 
// O(N), o(h)
void recursion(Node *root, int level, vector<int> &res)
{
        if(root==NULL) return ;
    // if left exist it will come first and as we pushed left res size will change and if left doesn't exist res size will be same for right and we can push it
        if(res.size()==level) res.push_back(root->data);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
}
vector<int> leftView(Node *root)
{
        vector<int> res;
        recursion(root, 0, res);
        return res;
}

// FOR RIGHT VIEW

vector<int> rightView(Node *root)
{
    vector<int>res;
    if(root == NULL)
        return res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        
        while(count--)
        {
            // will push last one
            if(count == 1)
                 res.push_back(q.front()->data);
            Node* temp = q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp ->right)
            {
                q.push(temp->right);
            }
        }
    }
    return res;
}

// recursive 
// O(N), o(h)
void recursion(Node *root, int level, vector<int> &res)
{
        if(root==NULL) return ;
    // if right exist it will come first and as we pushed right res size will change and if right doesn't exist res size will be same for left and we can push it
        if(res.size()==level) res.push_back(root->data);
        
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
}
vector<int> rightView(Node *root)
{
        vector<int> res;
        recursion(root, 0, res);
        return res;
}

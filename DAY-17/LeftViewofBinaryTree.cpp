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

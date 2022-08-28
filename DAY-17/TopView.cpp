//order traversal
vector<int> topView(Node *root)
    {
        vector<int>res;
  // queue to store nodes and its distances 
        queue<pair<Node*,int>>q;
  // to store first occuring element with this distance and sorting order of distances
        map<int,int>mp;
        if(root == NULL)
            return res;
        q.push({root,0});
        while(!q.empty())
        {
            int d = q.front().second;
            Node* t = q.front().first;
            q.pop();
            if(mp[d] == 0)
            {
                mp[d] = t-> data;
            }
            if(t->left)
               q.push({t->left,d-1});
            if(t->right)
               q.push({t->right,d+1});
        }
        for(auto m:mp)
        {
            res.push_back(m.second);
        }
        return res;
    }

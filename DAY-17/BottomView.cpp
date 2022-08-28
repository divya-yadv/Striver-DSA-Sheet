// same as top view but here we will keep updating till last occurence
vector <int> bottomView(Node *root) {
        vector<int>res;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        if(root == NULL)
            return res;
        q.push({root,0});
        while(!q.empty())
        {
            int d = q.front().second;
            Node* t = q.front().first;
            q.pop();
            mp[d] = t-> data;
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

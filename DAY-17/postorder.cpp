// recursive 
void postorder(TreeNode* root,vector<int>&res)
    {
        if(root == NULL)
            return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        postorder(root,res);
        return res;
    }

// itervative with two stacks
vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st1;
        stack<int>st2;
        if(root == NULL)
            return res;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp->val);
            if(temp->left)
               st1.push(temp->left);
            if(temp->right)
               st1.push(temp->right);
        }
        while(!st2.empty())
        {
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }

// iterative with one stack
vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st1;
        if(root == NULL)
            return res;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* temp = st1.top();
            st1.pop();
            res.push_back(temp->val);
            if(temp->left)
               st1.push(temp->left);
            if(temp->right)
               st1.push(temp->right);
        }
    // we stored in reverse order
      reverse(res.begin(),res.end());
        return res;
    }


// one more iterative

//

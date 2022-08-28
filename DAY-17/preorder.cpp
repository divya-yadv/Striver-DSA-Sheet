
// same as inorder O(N) -> visiting only once, O(N) -> max 
void preorder(TreeNode* root,vector<int>&res)
    {
        if(root == NULL)
            return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }

vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        if(root == NULL)
            return res;
        st.push(root);
        while(!st.empty())
        {
           // get root node
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
          // first push right and then left to get the right order
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
            
        }
        return res;
    }

// recursive solution
//iterative solution
// We are traversing N nodes and every node is visited exactly once. O(N), in worst case all child are left so in stack O(N) -> height of binary tree
 void inorder(TreeNode* root,vector<int>&res)
    {
        if(root == NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }


//iterative solution
// We are traversing N nodes and every node is visited exactly once. O(N), in worst case all child are left so in stack O(N) -> height of binary tree
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
 // we need stack because we need to move back from child to parent
        stack<TreeNode*>st;
        TreeNode* temp = root;
        while((!st.empty()) || (temp))
        {
         // we will got to extreme left for every temp
            while(temp)
            {
                st.push(temp);
                temp = temp->left;
            }
         // will take out leaf node
            temp = st.top();
            st.pop();
         // will push leaf node in res
            res.push_back(temp->val);
         // and we will go to right of that leaf node
            temp = temp->right;
        }
        return res;
    }

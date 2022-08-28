void traverse(BinaryTreeNode<int> *root,vector<vector<int>>&res)
{
    if(root == NULL)
        return;
  // preorder
    res[1].push_back(root->data);
    traverse(root->left,res);
  //inorder
    res[0].push_back(root->data);
    traverse(root->right,res);
  //postorder
    res[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res(3);
    traverse(root,res);
    return res;
}

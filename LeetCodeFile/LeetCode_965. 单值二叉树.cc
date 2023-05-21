bool isUnivalTree(struct TreeNode* root){
    if(root == NULL)
    {
        //根为空，返回真，不违反单值定义
        return true;
    }

    if(root->left && root->left->val != root->val)
    {
        //判断左值与根值是否相等
        return false;
    }

    if(root->right && root->right->val != root->val)
    {
        //判断右值与根值是否相等
        return false;
    }

    //返回   左节点结果与右节点结果
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
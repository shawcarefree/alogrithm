bool isSameTree(struct TreeNode* p, struct TreeNode* q){

    //都是空树，返回 真
    if(p == NULL && q == NULL)
    {
        return true;
    }

    //一个空，另一个非空
    if(p == NULL || q == NULL)
    {
        return false;
    }

    //都不为空
    if(p->val != q->val)
    {
        return false;
    }


    //递归去找左树的值与右树的值是否是相同结构
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    
    if(root == NULL)
    {
        return false;
    }

    //判断根的子树与给定的树(subroot)是否一样，有一个相同，自然就返回了
    return isSameTree(root,subRoot) 
    || isSubtree(root->left,subRoot) 
    || isSubtree(root->right,subRoot);
}

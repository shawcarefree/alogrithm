class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        //将根节点传入两次
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        
        if(p == nullptr && q != nullptr)
        {
            return false;
        }
        
        if(q == nullptr && p != nullptr)
        {
            return false;
        }
        
        return   (p->val == q->val) 
            && isSameTree(p->left, q->right) 
            && isSameTree(p->right, q->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root,root);
    }
};
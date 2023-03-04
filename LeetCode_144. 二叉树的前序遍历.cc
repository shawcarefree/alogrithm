void  _preorder(struct TreeNode* root,int* a,int* pi)
{
    
    if(root == NULL)
    {
        return;
    }
    a[(*pi)++] = root->val;
    _preorder(root->left,a,pi);
    _preorder(root->right,a,pi);
}
 int TreeSize(struct TreeNode* root)
 {
     return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
 }

int* preorderTraversal(struct TreeNode* root, int* returnSize){

    //记录节点个数
    int size = TreeSize(root);
    
    //创建数组
    int* a = malloc(sizeof(int)*size);
    
    *returnSize = size;

    int i = 0;
    _preorder(root,a,&i);
    return a;
}
返
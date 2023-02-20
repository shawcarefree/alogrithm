int getSum(struct TreeNode *root)
{
	if (root == NULL)
    {
        return 0;
    }
		
	return getSum(root->left) + getSum(root->right) + root->val;
}
int findTilt(struct TreeNode* root)
{
	if (root == NULL)
    {
        return 0;
    }
		
	return findTilt(root->left) + findTilt(root->right) + abs(getSum(root->left) - getSum(root->right));
}
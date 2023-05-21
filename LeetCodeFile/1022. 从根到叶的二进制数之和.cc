void DFS(struct TreeNode* root, int pathVal, int *sum)
{
	if (root == NULL)
    {
        return;
    }
		
	pathVal = (pathVal << 1) + root->val; 
	if (root->left == NULL && root->right == NULL)
    {
        *sum += pathVal;
    }
	DFS(root->left, pathVal, sum);
	DFS(root->right, pathVal, sum);
}
int sumRootToLeaf(struct TreeNode* root)
{
	int sum = 0;
	DFS(root, 0, &sum);
	return sum;
}
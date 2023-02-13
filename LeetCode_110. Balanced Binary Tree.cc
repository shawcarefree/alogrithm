struct Info
{
	bool isBalanced;
	int height;

	Info(bool i, int h)
		:isBalanced(i)
		, height(h)
	{}
};
class Solution {
public:
	Info* process(TreeNode* root)
	{
		if (root == nullptr)
		{
			return new Info(true, 0);
		}

		Info* leftInfo = process(root->left);
		Info* rightInfo = process(root->right);

		int height = std::max(leftInfo->height, rightInfo->height) + 1;
		bool isBalanced =
			leftInfo->isBalanced
			&& rightInfo->isBalanced
			&& (((leftInfo->height - rightInfo->height) < 2) && ((leftInfo->height - rightInfo->height) > -2));

		return new Info(isBalanced, height);
	}
    
    //调用自己写的递归
	bool isBalanced(TreeNode* root) {
		return process(root)->isBalanced;
        
	}
};
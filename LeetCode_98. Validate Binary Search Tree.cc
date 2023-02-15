struct Info
{
	bool isBST;
	int max;
	int min;

	Info(int is,int ma,int mi)
		:isBST(is)
		,max(ma)
		,min(mi)
	{}
};
class Solution {
public:
Info* process(TreeNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	Info* leftInfo = process(root->left);
	Info* rightInfo = process(root->right);
	
	int max = root->val;
	int min = root->val;
	

	//确认最大最小值
	if (leftInfo != nullptr)
	{
		max = std::max(leftInfo->max, max);
		min= std::min(leftInfo->min, min);
	}

	if (rightInfo != nullptr)
	{
		max = std::max(rightInfo->max, max);
		min = std::min(rightInfo->min, min);
	}
	
	//确认是否为搜索树
	bool isBST = true;

	if (leftInfo != nullptr && !leftInfo->isBST)
	{
		isBST = false;
	}

	if (rightInfo != nullptr && !rightInfo->isBST)
	{
		isBST = false;
	}
	
	bool leftMaxLessRoot = leftInfo == nullptr ? true : (leftInfo->max < root->val);
	bool rightMinMoreRoot = rightInfo == nullptr ? true : (rightInfo->min > root->val);

	if (!(leftMaxLessRoot && rightMinMoreRoot))
	{
		isBST = false;
	}

	return new Info(isBST, max, min);
}
    
    
    bool isValidBST(TreeNode* root) {
        return process(root)->isBST;
    }
};
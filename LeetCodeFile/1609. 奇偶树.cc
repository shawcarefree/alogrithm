#define N 100002
bool isEvenOddTree(struct TreeNode* root)
{
	//申请队列空间，使用数组模拟队列
	struct TreeNode *queue[N];
	int front = 0;
	int rear = 0;
	int odd = 0; //odd用于判断奇偶层[0:偶数层，1:奇数层]
	int pre; //表示当前行判断节点的前驱节点
	queue[rear++] = root;
	while (front != rear)
	{
		int cnt = rear - front;
		if (odd == 1)
			pre = INT_MAX;
		if (odd == 0)
			pre = INT_MIN;
		for (int i = 0; i < cnt; i++)
		{
			root = queue[front++];
			//偶数行判断
			if ((odd == 1) && (root->val % 2 != 0 || pre <= root->val))
				return false;
			//奇数行判断
			if ((odd == 0) && (root->val % 2 != 1 || pre >= root->val))
				return false;
			pre = root->val;
			if (root->left)
				queue[rear++] = root->left;
			if (root->right)
				queue[rear++] = root->right;
		}
		//控制奇偶行标记
		odd = (odd + 1) % 2;
	}
	return true;
}
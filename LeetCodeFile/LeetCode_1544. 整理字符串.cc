char * makeGood(char *s)
{
	int len = strlen(s);
	//使用字符数组模拟栈结构
	char *ans = (char *)malloc(len + 1);
	int top = 0;
	for (int i = 0; i < len; ++i)
	{
		ans[top++] = s[i];
		//判断栈顶的两个元素是否互为大小写
		if (top >= 2 && (ans[top - 1] + 32 == ans[top - 2] || ans[top - 1] - 32 == ans[top - 2]))
			top -= 2; //删除栈顶的两个元素
	}
	ans[top] = '\0';
	return ans;
}
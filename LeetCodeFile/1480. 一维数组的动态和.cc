int *runningSum(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
    {
        int sum = 0;
        // 对i之前的数据累加求和
        for (int j = 0; j <= i; ++j)
        {
            sum += nums[j];
        }
        ans[i] = sum;
    }
    *returnSize = numsSize;
    return ans;
}
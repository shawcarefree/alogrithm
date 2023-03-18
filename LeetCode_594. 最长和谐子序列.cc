int cmp(const void *x, const void *y)
{
    return *(int*)x - *(int*)y;
}

int findLHS(int* nums, int numsSize){
    //排序 + 滑动窗口
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    int ans = 0;
    int begin = 0;
    int end = 0;
    for (end = 1; end < numsSize; end++)
    {
        if (nums[end] - nums[begin] > 1)
        {
            begin++;
        } 
        if (nums[end] - nums[begin] == 1)
        {
            ans = ans > end-begin+1 ? ans : end-begin+1;
        }
    }

    return ans;

}

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int *arr = (int *)calloc(numsSize + 1,sizeof(int));
    int *brr = (int *)calloc(*returnSize,sizeof(int));
    int old_sum = 0;
    int new_sum = 0;
    for(int i = 0;i<numsSize;i++)
    {
        if(arr[nums[i]] == 1)
        {
            brr[0]=nums[i];
        }
        arr[nums[i]] = 1;
        old_sum += nums[i];
        new_sum +=i + 1;
    }
    brr[1]=new_sum-(old_sum-brr[0]);
    free(arr);
    return brr;
}
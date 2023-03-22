int pivotIndex(int* nums, int numsSize){
    for(int i=0;i<numsSize;i++)
    {
        int left_sum=0;
        int right_sum=0;
        for(int j=0;j<numsSize;j++)
        {
            if(j<i)
            {
                left_sum+=nums[j];
            }
            else if(j>i)
            {
                right_sum+=nums[j];
            }

        }
        if(left_sum==right_sum)
        {
            return i;
        }
    }
    return -1;
}
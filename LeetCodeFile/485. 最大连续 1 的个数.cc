int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count=0;
    int Max=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==1)
        {
            count++;
        }
        else
        {
            if(count>Max)
            {
                Max=count;
            }
            count=0;
        }
    }
    Max=count > Max ? count:Max;
    return Max;
}
int dominantIndex(int* nums, int numsSize){
    int Max=nums[0];
    int k=0;
    for(int i = 0;i < numsSize;i++)
    {
        if(nums[i]>Max)
        {
            k=i;
            Max=nums[i];
        }
    }
    for(int j=0;j<numsSize;j++)
    {
       if(j!=k)
       {
        if((nums[j]*2)<=Max)
        {
            continue;
        }
        else
        {
            return -1;
        }
        
       }
    }
    return k;
}
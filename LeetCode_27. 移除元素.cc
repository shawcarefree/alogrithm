int removeElement(int* nums, int numsSize, int val)
{
    int *pa = nums;
    int *pb = nums;
    int i = 0;
    for(i = 0;i < numsSize;i++)
    {
        if((*pb) != val)
        {
            *pa = *pb;
            pa++;
            pb++;
        }
        else
        {
            pb++;
        }
    }
    return pa-nums;
}
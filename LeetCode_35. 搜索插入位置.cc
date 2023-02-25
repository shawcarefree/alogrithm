int searchInsert(int* nums, int numsSize, int target){

    int L = 0;
    int R = numsSize - 1;

    while(L <= R)
    {
        int mid = L + ((R - L)>>1);

        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    
    
    return L;
   
}
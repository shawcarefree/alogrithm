class Solution
{
public:
    void moveZeroes(vector<int>& nums )
    {
        // current 
        // destination:finished section of no-zeroes
        int cur = 0;
        int dest = 0;


        for(cur = 0; cur < nums.size(); cur++)
        {
            if(nums[cur] != 0)
            {
                swap(nums[cur],nums[dest++]);
            }
        }
    }
};
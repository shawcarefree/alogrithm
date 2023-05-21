class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            if(nums[left] == left + 1)
            {
                left++;
            }
            else if(nums[left] <= left || nums[left] > right || nums[nums[left] - 1] == nums[left])//不需要的数字
            {
                std::swap(nums[left],nums[--right]);
                //nums[left] = nums[--right];
            }
            else
            {
                //将当前数字换到他本该出现的位置
                std::swap(nums[left],nums[nums[left] - 1]);
            }
        }

        return left + 1;
    }
};
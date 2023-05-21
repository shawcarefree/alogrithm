class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        size_t length = nums.size();
        size_t len = length - 1;
        if (length < 2)
        {
            return true;
        }

        int max_ = nums[0];
        for (int i = 0; i < length; i++)
        {

            //if (max_ >= len) return true;
            if (i > max_) return false;


            max_ = std::max(max_, i + nums[i]);
        }

        return true;
    }
};
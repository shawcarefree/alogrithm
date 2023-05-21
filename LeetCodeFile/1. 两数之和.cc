class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //如果能找到符合题意的两个值,返回,不符合将当前值加入map中,为后续元素提供选择基础
	// K为元素值;V为元素的下标
        std::unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++)
        {

            if(map.find(target - nums[i]) != map.end())
            {
                return {map[target - nums[i]],i};
            }

            map[nums[i]] = i;
        }
        
        return {-1,-1};
    }
};
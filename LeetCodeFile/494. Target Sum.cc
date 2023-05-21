class Solution {
private:
    int process(std::vector<int>& arr,int index,int rest)
    {
        if(index == arr.size())//没有数字可挑选
        {
            return rest == 0 ? 1 : 0;
        }

        return process(arr,index + 1,rest - arr[index]) + process(arr,index + 1,rest + arr[index]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return process(nums,0,target);
    }
};
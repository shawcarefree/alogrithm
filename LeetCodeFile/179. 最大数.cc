class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return y + x < x + y; });
        if (strs[0] == "0")
            return "0";
        for (int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};
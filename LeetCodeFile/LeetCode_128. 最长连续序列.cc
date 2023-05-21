class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_map<int,int> map;
		int len = 0;
		for (auto num : nums) 
        {

            if(map.find(num) == map.end())
            {
                map[num] = 1;

                int preLen = (map.find(num - 1) != map.end()) ? map[num - 1] : 0;
                int posLen = (map.find(num + 1) != map.end()) ? map[num + 1] : 0;
				int all = preLen + posLen + 1;

                map[num - preLen] = all;
                map[num + posLen] = all;
                len = std::max(len,all);
			}
		}
		return len;
    }
};
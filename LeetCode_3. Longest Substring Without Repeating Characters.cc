class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
        {
            return 0;
        }

        int map[256] = {0};
        for(int i = 0; i < 256; i++)//A~z 的ASCII码表
        {
            map[i] = -1;
        }

        int len = 0;
        int pre = -1;//字符上一次出现的位置
        int cur = 0;//当前字符的位置与上一次字符出现位置的差

        for(int i = 0; i < s.size(); i++)
        {
            pre = std::max(pre,map[s[i]]);
            cur = i - pre;

            len = std::max(len,cur);
            map[s[i]] = i;
        }

        return len;
    }
};
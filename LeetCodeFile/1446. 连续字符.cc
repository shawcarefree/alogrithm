class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0)
        {
            return 0;
        }
        if(s.size() == 1)
        {
            return 1;
        }

        int count = 1;
        int ans = 1;

        for(int i = 0; i < s.size();i++)
        {
            if(s[i] == s[i + 1])
            {
                count++;
            }
            else
            {
                if(count >= ans)
                {
                    ans = count;
                }

                count = 1;
            }
        }

        return ans;
    }
};
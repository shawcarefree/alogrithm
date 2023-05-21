class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for(auto e : s)
        {
            arr[e - 'a']++;
        }

        for(size_t i = 0; i < s.size();i++)
        {
            if(arr[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    } 
};

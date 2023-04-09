class Solution {
public:
    bool halvesAreAlike(string s) {
        int s_mid = s.size() / 2;
        int count = 0;
        for(int i = 0; i < s_mid; i++)
        {
            if(findVovel(s[i]))
            {
                count++;
            }
            if(findVovel(s[s_mid + i]))
            {
                count--;
            }
        }

        return count == 0;
    }
private:
    std::set<char> _vovel = {'a','e','i','o','u','A','E','I','O','U'};

    bool findVovel(char ch)
    {
        if(_vovel.find(ch) != _vovel.end())
        {
            return true;
        }
        else
        {
            return false;
        }
}
};
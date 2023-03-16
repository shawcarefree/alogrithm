class Solution {
public:
    string reverseWords(string s) {

        int start = 0;
        int end = 0;
        while(start < s.size())
        {
            end = s.find(' ',start);

            if(end == std::string::npos)
            {
                end = s.size();
            }
            std::reverse(s.begin() + start,s.begin() + end);
            start = end + 1;
        }

        return s;
    }
};
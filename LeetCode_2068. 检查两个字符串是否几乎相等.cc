class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int wordArr[26] = {0};

        for(int i = 0; i < word1.size(); i++)
        {
            wordArr[word1[i] - 'a']--;
        }

  
        for(int i = 0; i < word2.size(); i++)
        {
            wordArr[word2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(abs(wordArr[i]) > 3)
            {
                return false;
            }
        }

        return true;
    }
};
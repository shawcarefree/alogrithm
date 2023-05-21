class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.size() == 0)
        {
            return ans;
        }

        string str = digits;
        string path;
        path.resize(digits.size());
        process(str,0,path,ans);

        return ans;
    }

private:
    void process(string& str,int index,string& path,vector<string>& ans)
    {
        if(index == str.size())
        {
            ans.push_back(path);
        }
        else
        {
            char* cands = phone[str[index] - '2'];

            for(int i = 0; i < strlen(cands);i++)
            {
                path[index] = cands[i];
                process(str,index + 1,path,ans);
            }
        }
    }

    vector<char*> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};
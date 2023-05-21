class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = 0,j = array[0].size() - 1;

        while(i < array.size() && j >= 0)
        {
            if(target < array[i][j])
            {
                j--;//排除当前列
            }
            else if(target > array[i][j])
            {
                i++;//排除当前行
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here

        int index = 0;
        int size = array.size();


        for(int i = 0; i < size; i++)
        {
            if((array[i] & 1) == 1)
            {
                //奇数
                std::swap(array[i], array[index++]);
            }
        }

        return array;
    }
};
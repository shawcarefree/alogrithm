class Solution {
public:
    void reOrderArray(vector<int> &array) {

        int k = 0;//标记下一个奇数位插入的位置
        int size = array.size();

        for(int i = 0; i < size;i++)
        {
            if((array[i] & 1) == 1)//判断是否为奇数,等于1就是奇数
            {
                int temp = array[i];
                int j = i;
                while(j > k)//利用插入排序,保证奇左偶右
                {
                    array[j] = array[j - 1];
                    j--;
                }
                
                array[k] = temp;//保证相对位置不变
                k++;
            }
        }
    }
};
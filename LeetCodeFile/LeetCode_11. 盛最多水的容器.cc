class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right)//先看两边谁最低,让最低的一边去移动->期待找到一个更高的标杆,让其盛水量大于最低杆
        {
            max = std::max(max,std::min(height[left],height[right]) * (right - left));

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max;
    }
};
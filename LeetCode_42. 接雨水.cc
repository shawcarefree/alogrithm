class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() < 2)
        {
            return 0;
        }

        //第i个位置能存几个水? 取决于左右相邻
        int N = height.size();
        int left = 1;
        int right = N - 2;

        int leftMax = height[0];
        int rightMax = height[N - 1];

        int water = 0;

        while(left <= right)
        {
            if(leftMax <= rightMax)
            {
				water += std::max(0, leftMax - height[left]);//负值不取
				leftMax = std::max(leftMax, height[left++]);
			}
            else 
            {
				water += std::max(0, rightMax - height[right]);
				rightMax = std::max(rightMax, height[right--]);
			}
        }

        return water;
    }
};
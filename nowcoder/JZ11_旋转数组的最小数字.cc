class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        
        while (left < right) 
        {
            int mid = (left + right) >> 1;
            if (rotateArray[mid] < rotateArray[right]) 
            {
				//12345
				//有可能是最小的,不要排除当前mid,即直接赋值
                right = mid;
            } 
            else if (rotateArray[mid] > rotateArray[right]) 
            {
				//34512,arr[mid]不可能为最小值,可以排除当前mid,即mid+1
                left = mid + 1;
            }
            else 
            {
				//打破循环,left为ans下标
                right--;
            }
        }

        return rotateArray[left];
    }
};
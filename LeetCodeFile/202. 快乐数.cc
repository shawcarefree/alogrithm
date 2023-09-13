class Solution {
public:
	int bitSum(int n) // 返回每一位的平方和
	{
		int sum = 0;
		while(n)
		{
			int t = n % 10;
			sum += t * t;
			n /= 10;
		}
		
		return sum;
	}
    bool isHappy(int n) {
		int slow = n;
		int fast = bitSum(n);
		
		while(slow != fast)
		{
			slow = bitSum(slow);
			fast = bitSum(bitSum(fast));
		}
		
		return slow == 1;
		
    }
};
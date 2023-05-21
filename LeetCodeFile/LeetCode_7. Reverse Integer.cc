class Solution {
public:
	int reverse(int x) {

		//一律转换为负数 -- 负数的绝对值域比正数绝对值域大
		bool neg = ((x >> 31) & 1 == 1);
		x = neg ? x : -x;

		int m = INT_MIN / 10;
		int o = INT_MIN % 10;

		int res = 0;
		while (x != 0)
		{
			if (res < m || (res == m && x & 10 < o))//防止溢出
			{
				return 0;
			}
			res = (res * 10) + (x % 10);
			x /= 10;
		}

		return neg ? res : abs(res);
	}
};
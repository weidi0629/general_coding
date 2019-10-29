/*
这个dp有点brute force, 但是bitset操作需要学一下
*/

class Solution {
public:
	typedef bitset<26> charbit; // typedef make things simpler
  
	int maxLength(vector<string>& arr) {
		int maxlen = 0;
		vector<charbit> dp{charbit()};
		for (auto a : arr)
		{
			charbit b = tocharbit(a);
			if (b.count() != a.size())	continue; // count是统计1的位数
			int len = dp.size();
			for (int i =0;i<len;i++)
			{
				if ((b&dp[i]).count())	continue;
				maxlen = max(maxlen, (int)(b.count()+dp[i].count())); //(int)的用法 
				dp.emplace_back((b | dp[i]));
			}
		}
		return maxlen;
	}
  
	charbit tocharbit(const string& s)
	{
		charbit bs;
		for (auto c : s) bs.set(c - 'a'); 
		return bs;
	}
};

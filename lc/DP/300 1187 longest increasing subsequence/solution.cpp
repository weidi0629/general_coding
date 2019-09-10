/*
首先先做300， lis。 
方法1是building tail in the fly 
(1) if x is larger than all tails, append it, increase the size by 1
(2) if tails[i-1] < x <= tails[i], update tails[i]
tail[i] 表示len = i 的数组，最小的tail
比如 [4,5] 
     [4,5,6]
现在来一个7， 他不会去更新len=2的数组，因为7比6还大，所以至少要更新len=3的数组
*/

public int lengthOfLIS(int[] nums) {
    int[] tails = new int[nums.length]; //
    int size = 0;
    for (int x : nums) {
        int i = 0, j = size;
        while (i != j) { // i,j都是index，本题中代表长度
            int m = (i + j) / 2;
            if (tails[m] < x)
                i = m + 1;
            else
                j = m;
        }
        tails[i] = x; // 其实binary search停在的是i-1的位置，所以是更新 i(i是长度)
        if (i == size) ++size;
    }
    return size;
}

/*
方法2是dp
dp[i]表示截止到i，最长的数组是多少, 应该是比较好理解的  
*/

public int lengthOfLIS(int[] nums) 
	{
		// Base case
		if(nums.length <= 1) 
			return nums.length;

		// This will be our array to track longest sequence length
		int dp[] = new int[nums.length];

		// Fill each position with value 1 in the array
		for(int i=0; i < nums.length; i++)
			dp[i] = 1;


		// Mark one pointer at i. For each i, start from j=0.
		for(int i=1; i < nums.length; i++)
		{
			for(int j=0; j < i; j++)
			{
				// It means next number contributes to increasing sequence.
				if(nums[j] < nums[i])
				{
					// But increase the value only if it results in a larger value of the sequence than T[i]
					// It is possible that T[i] already has larger value from some previous j'th iteration
					if(dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}

		// Find the maximum length from the array that we just generated 
		int longest = 0;
		for(int i=0; i < T.length; i++)
			longest = Math.max(longest, dp[i]);

		return longest;
	}
  
  
  /*
  1187
  现在开始1187，参考的例子在下面。附上在leetcode上的解释，加上一个random due的补充。下面是自己cpp++，可能有错，但是编译能过, 有时间可以跟java
  版本做比较。
  
  这题的take away 是， 在思考subproblem 跟 problem时， dp[i] = dp[sub] +c, 这个c要仔细考虑
  
  I find the most confusing part is the formula 'dp[i] = Math.min(dp[i], dp[j] + change)'. say arry [0, 3, 2, 3, 6, 8]. When change arr[1] to arr[5], we change 2,3,6. But we only need to change 2,3, right? but if we really do this, the dp formula would become dp[i] = optimal sub1 + optimal sub2, which is not we want for a dp formula.
So here, we sacrifice 6, to cover the shit like [0, 3, 2, 3, 1, 8] when changing arr[1] to arr[5], we just take the worst case every time...
For the original arr [0, 3, 2, 3, 6, 8], the case we want would be cover when change arr[4] and arr[5], since dp[4] would be optimal, we don't need to worry that 6 issue anymore. That's kind of min-max idea in it.
I wouldn't say i'm super comfortable with this explanation, if some one got more intuitive idea, please share...


@WZ193 "If array arr1 is [-INF, 0, 3, 2, 3, 6, 8, +INF], and start = 2, end = 6, then we change 2,3,6". 
This is because arr2 can be [3,5,6,7] and for such case, only possibility is to replace 2,3,6 with 5,6,7 and no other option. 
Also remember that dp[6] = min(...., dp[2] + check(arr1,arr2,2,6), dp[3] + check(arr1,arr2,3,6), dp[4] + check(arr1,arr2,4,6), ...), 
so all cases will get handled ultimately.
  
  https://leetcode.com/problems/make-array-strictly-increasing/discuss/377495/Java-dp-solution-%3A-A-simple-change-from-Longest-Increasing-Subsequence
  */
  
  class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // take care of arr2
        vector<int>::iterator ip; 
        ip = std::unique(arr2.begin(), arr2.end()); 
        arr2.resize(std::distance(arr2.begin(), ip));
        
        // make some changes for arr1
        int n = arr1.size();
        vector<int> dp(n+1, INT_MAX);// how many operation needs for making strictly increasing
        dp[0] = 0;
        arr1.insert(arr1.begin(), INT_MIN);
        arr1.emplace_back(INT_MAX);
        
        for(int i=0; i<n+1;i++){
            for(int j=0; j<i; j++){
                if(arr1[i] > arr1[j]){
                    int count = change(arr2, j, i, arr1[i]);
                    if(count != -1)
                        dp[i] = min(dp[i], dp[j]+ count);
                }
            }
        }   
        return dp[n-2];        
    }
    
    int change(vector<int>& arr2, int start, int end, int mx){
        if(start +1 == end)
            return 0;
        vector<int>::iterator l = lower_bound(arr2.begin(), arr2.end(),start);
        int ll = l - arr2.begin();
        int len = end - start -1;
        if(ll+len < arr2.size() && arr2[ll+len] < mx ){
            return len;
        }
        return -1;
    } 
};
  
  
  
  
  
  
